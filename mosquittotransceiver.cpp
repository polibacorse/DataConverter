/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code have been inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#include "mosquittotransceiver.h"

#include <QByteArray>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <mosquitto.h>

namespace {
void on_connect_wrapper(struct mosquitto *, void *that, int rc)
{
    MosquittoTransceiver *m = reinterpret_cast<MosquittoTransceiver *>(that);
    m->_onConnect(rc);
}

void on_disconnect_wrapper(struct mosquitto *, void *that, int rc)
{
    MosquittoTransceiver *m = reinterpret_cast<MosquittoTransceiver *>(that);
    m->_onDisconnect(rc);
}

void on_message_wrapper(struct mosquitto *, void *that, const struct mosquitto_message *message)
{
    MosquittoTransceiver *m = reinterpret_cast<MosquittoTransceiver *>(that);
    m->_onMessage(message);
}
} /* namespace _ */

MosquittoTransceiver::MosquittoTransceiver(QObject *parent) : QThread(parent), isConnected_{false}
{
    mosquitto_lib_init();

    auto onConnected = [this]() {
        isConnected_ = true;
        emit connected();
        emit isConnectedChanged();
    };

    auto onDisconnected = [this]() {
        isConnected_ = false;
        emit disconnected();
        emit isConnectedChanged();
    };

    auto onMessage = [this](QString topic, QJsonObject payload) {
        /* emit with queued connection */
        emit message(topic, payload);
    };

    /* QueuedConnection is needed, so callbacks are handled outside mosquitto thread */
    QObject::connect(this, &MosquittoTransceiver::_connected, this, onConnected, Qt::QueuedConnection);
    QObject::connect(this, &MosquittoTransceiver::_disconnected, this, onDisconnected, Qt::QueuedConnection);
    QObject::connect(this, &MosquittoTransceiver::_message, this, onMessage, Qt::QueuedConnection);

    //qDebug() << "MosquittoTransceiver initialized.";

    startTime_.start();
}

MosquittoTransceiver::~MosquittoTransceiver()
{
    /* Force disconnection and stop the thread */
    this->disconnect();

    mosquitto_lib_cleanup();
}

void MosquittoTransceiver::connect()
{
    this->QThread::start();
}

void MosquittoTransceiver::disconnect()
{
    continueRunning_ = false;

    if (!this->wait(2000)) {
        qWarning() << "Timeout while waiting for mosquitto disconnection.";
    }
}

void MosquittoTransceiver::run()
{
    int rc = 0;
    auto mosq = mosquitto_new("DataConverter", true, this);

    if (!mosq) {
        std::runtime_error{"MosquittoTransceiver: cannot instantiate mosquitto client."};
    }

    mosquitto_connect_callback_set(mosq, on_connect_wrapper);
    mosquitto_disconnect_callback_set(mosq, on_disconnect_wrapper);
    mosquitto_message_callback_set(mosq, on_message_wrapper);

    continueRunning_ = true;

    rc = mosquitto_connect(mosq, "localhost", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS) {
        qCritical() << "MosquittoReceiver: cannot connect!";
        mosquitto_destroy(mosq);

        return;
    }

    //qDebug() << "MosquittoReceiver: connected. Start looping...";

    while (continueRunning_) {
        rc = mosquitto_loop(mosq, 500, 1); // we need high performance and quasi-realtime data elaboration

        if (continueRunning_ && rc) {
            qWarning() << "Mosquitto connection error. Thread will sleep.";
            QThread::sleep(1);
            mosquitto_reconnect(mosq);
        }

        mutex_.lock();

        while (!subscribeQueue_.isEmpty()) {
            const auto &topic = subscribeQueue_.dequeue();

            mosquitto_subscribe(mosq, nullptr, topic.toStdString().c_str(), 0); // QoS 0: just stream it
        }

        while (!publishQueue_.isEmpty()) {
            const auto& subscription = publishQueue_.front();
            auto topic = std::get<0>(subscription);
            auto payload = std::get<1>(subscription);
            mosquitto_publish(mosq, nullptr, topic.toStdString().c_str(), payload.size(), payload.constData(), 0, false);
            publishQueue_.pop_front();
        }

        mutex_.unlock();
    }

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
}

void MosquittoTransceiver::publish(QString topic, QJsonObject jpayload)
{
    //qDebug() << "Publishing to " << topic;

    /* Debug - Time elapsed */
    mutex_startTime_.lock();
    //qDebug() << "Elapsed time from last arrive: " << startTime_.elapsed() << "ms";
    mutex_startTime_.unlock();

    auto payload = QJsonDocument(jpayload).toJson(QJsonDocument::Compact);

    mutex_.lock();
    publishQueue_.push_back(std::make_tuple(topic, payload));
    mutex_.unlock();
}

void MosquittoTransceiver::subscribe(QString topic)
{
    //qDebug() << "Subscribing to " << topic;

    mutex_.lock();
    subscribeQueue_.enqueue(topic);
    mutex_.unlock();
}

void MosquittoTransceiver::_onConnect(int rc)
{
    if (rc != MOSQ_ERR_SUCCESS) {
        qWarning() << "Mosquitto connection failed!";
        return;
    }

    emit _connected();
}

void MosquittoTransceiver::_onDisconnect(int rc)
{
    if (rc != MOSQ_ERR_SUCCESS) {
        qWarning() << "Mosquitto disconnected unexpectedly!";
    }

    emit _disconnected();
}

void MosquittoTransceiver::_onMessage(const mosquitto_message *message)
{
    QString topic{message->topic};
    QByteArray payload{reinterpret_cast<const char *>(message->payload), message->payloadlen};

    try {
        auto jdoc = QJsonDocument::fromJson(payload);
        auto jpayload = jdoc.object();

        mutex_startTime_.lock();
        startTime_.restart();
        mutex_startTime_.unlock();

        //qDebug() << "Message arrived from " << topic;
        //qDebug() << "Payload in entrance: " << payload;

        emit _message(topic, jpayload);
    } catch (...) {
        qWarning("Something happened during json message parsing.");
    }
}

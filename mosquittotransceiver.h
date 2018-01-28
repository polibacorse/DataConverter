/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code have been inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#ifndef MOSQUITTOTRANSCEIVER_H
#define MOSQUITTOTRANSCEIVER_H

#include <QByteArray>
#include <QElapsedTimer>
#include <QHash>
#include <QJsonObject>
#include <QMutex>
#include <QQueue>
#include <QThread>

struct mosquitto_message;

class MosquittoTransceiver : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool isConnected MEMBER isConnected_ NOTIFY isConnectedChanged)

public:
    MosquittoTransceiver(QObject *parent = nullptr);
    virtual ~MosquittoTransceiver();

    Q_INVOKABLE void connect();
    Q_INVOKABLE void disconnect();

    Q_INVOKABLE void publish(QString topic, QJsonObject payload);
    Q_INVOKABLE void subscribe(QString topic);

signals:
    void connected();
    void disconnected();
    void message(QString topic, QJsonObject payload);

    void isConnectedChanged();

/* internal use only from here below */
signals:
    void _connected();
    void _disconnected();
    void _message(QString topic, QJsonObject payload);

public:
    void _onConnect(int);
    void _onDisconnect(int);
    void _onMessage(const mosquitto_message *);

private:
    void run();

    QMutex mutex_;
    QQueue<std::tuple<QString, QByteArray>> publishQueue_;
    QQueue<QString> subscribeQueue_;
    bool continueRunning_;
    bool isConnected_;

    /* Metrics for debugging purposes */
    QMutex mutex_startTime_;
    QElapsedTimer startTime_;
};

#endif // MOSQUITTOTRANSCEIVER_H

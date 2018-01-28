#ifndef DATACONVERTER_H
#define DATACONVERTER_H

#include "mosquittotransceiver.h"

#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QRunnable>

namespace {
struct CANFrame {
    const QJsonValue id;
    const QJsonValue time;
    const QJsonArray data;
};
}

class DataConverter : public QObject,  public QRunnable
{
    Q_OBJECT

public:
    DataConverter(QObject *parent = nullptr);

signals:
    void publish(QString topic, QJsonObject data);

public slots:
    void message(QString topic, QJsonObject data);

private:
    void run();
    struct CANFrame JSON2CAN(const QJsonObject);
    void format(struct CANFrame);

    QEventLoop eventLoop;
    MosquittoTransceiver *transceiver;
};

#endif // DATACONVERTER_H

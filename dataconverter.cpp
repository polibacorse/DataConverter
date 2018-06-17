#include "dataconverter.h"
#include <QDebug>

#include <QJsonObject>
#include <QByteArray>

DataConverter::DataConverter(QObject *parent) : QObject(parent), eventLoop{this}
{
    transceiver = new MosquittoTransceiver(this);
    transceiver->connect();
    transceiver->subscribe("data/raw");
}

void DataConverter::run()
{
    connect(transceiver, SIGNAL(message(QString, QJsonObject)), this, SLOT(message(QString, QJsonObject)));
    connect(this, SIGNAL(publish(QString,QJsonObject)), transceiver, SLOT(publish(QString,QJsonObject)));

    emit eventLoop.exec();
}

void DataConverter::message(QString /* unused */, QJsonObject data)
{
    this->format(this->JSON2CAN(data));
}

struct CANFrame DataConverter::JSON2CAN(const QJsonObject data)
{
    struct CANFrame frame = {
        .id = data["id"].toInt(),
        .time = data["time"].toInt(),
        .data = data["data"].toArray(),
    };

    qDebug() << "Packet arrived from ID: " << frame.id.toInt();
    return frame;
}

void DataConverter::format(struct CANFrame frame)
{
    double value;
    QByteArray framedata(nullptr, 4);
    QString topicPrefix("data/formatted/");
    QString topicName;

    switch (frame.id.toInt()) {
        case 747:
        topicName = "a1x";
        value = ((frame.data[0].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[1].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a2x";
        value = ((frame.data[2].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[3].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a3x";
        value = ((frame.data[4].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[5].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a1y";
        value = ((frame.data[6].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[7].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 748:
        topicName = "a2y";
        value = ((frame.data[0].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[1].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a3y";
        value = ((frame.data[2].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[3].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 749:
        topicName = "a1z";
        value = ((frame.data[0].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[1].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a2z";
        value = ((frame.data[2].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[3].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a3z";
        value = ((frame.data[4].toInt() * 3.0) / 255.0) - 1.5 + (frame.data[5].toInt() / 1000.0);
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 750:
        topicName = "slip_ok";
        value = frame.data[7].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "auto_acc_flag";
        value = (frame.data[0].toInt() & 128) / 128;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "debug_mode";
        value = (frame.data[0].toInt() & 64) / 64;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "datalog_on-off";
        value = (frame.data[0].toInt() & 32) / 32;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "telemetria_on-off";
        value = (frame.data[0].toInt() & 16) / 16;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "lap_close";
        value = frame.data[1].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 751:
        topicName = "target_rpm_up";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "shift_duration";
        value = (frame.data[2].toInt() * 256.0) + frame.data[3].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "time_0-100";
        value = (frame.data[4].toInt() * 256.0) + frame.data[5].toInt();
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "time_0-75";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 752:
        topicName = "altitude";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) / 10.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gps_speed";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) / 10.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "satellite";
        value = frame.data[4].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "fix";
        value = frame.data[5].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gps_time";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 753:
        topicName = "latitude";
        // Here from high-level value of QJsonArray to a double is tricky.
        for (int i = 0; i < 4; i++) {
            framedata[i] = frame.data[i].toInt();
        }
        value = *(reinterpret_cast<const double*>(framedata.constData()));
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 754:
        topicName = "longitude";
        // Here from high-level value of QJsonArray to a double is tricky.
        for (int i = 0; i < 4; i++) {
            framedata[i] = frame.data[i].toInt();
        }
        value = *(reinterpret_cast<const double*>(framedata.constData()));
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 768:
        topicName = "rpm";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tps";
        value = (frame.data[2].toInt() * 100.0) / 255.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "map";
        value = (frame.data[4].toInt() * 256.0) + frame.data[5].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "lambda";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 769:
        topicName = "derivata_farfalla";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "dmap";
        value = (frame.data[2].toInt() * 256.0) + frame.data[3].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 770:
        topicName = "vhspeed";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 0.1;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "draxspeed";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 0.1;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "slip_calc";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 50.0 / 255.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "osasplip";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 0.25;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 772:
        topicName = "terogpianoquotato";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "terog";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "sabase";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 0.25;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "sa";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 0.25;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 774:
        topicName = "gear";
        value = frame.data[1].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gear_shift_time_remain";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "poil";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "pfuel";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 775:
        topicName = "baro";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt());
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "lnr3i";
        value = (frame.data[2].toInt() * 256.0) + frame.data[3].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "lnr4i";
        value = (frame.data[4].toInt() * 256.0) + frame.data[5].toInt();
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 776:
        topicName = "vbattdir";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 18.0 / 1024.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "vbattkey";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 18.0 / 1024.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 779:
        topicName = "th20";
        value = (((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 160.0 / 65535.0) - 10.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "toil";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 18.0 / 1024.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tmp";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 18.0 / 1024.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tair";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 18.0 / 1024.0;
        qDebug() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        default:
        qDebug() << "No valid packet found! ID: " << frame.id.toInt();
        return;
    }
}

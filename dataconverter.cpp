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

    //qInfo() << "Packet arrived from ID: " << data;
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
        value = (((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 12.0 / 16383.0) - 6.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "a1y";
        value = (((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 12.0 / 16383.0) - 6.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "steer_pos";
        value = ((frame.data[4].toInt() * 256.0 + frame.data[5].toInt()) * 360.0 / 16383.0) - 180.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 748:
        topicName = "fldamp";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 75.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "frdamp";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 75.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "rldamp";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 75.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "rrdamp";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 75.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 749:
        topicName = "current1";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 48.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "current2";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 48.0 / 16383.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 750:
        topicName = "slip_ok";
        value = frame.data[7].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 751:
        topicName = "target_rpm_up";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "shift_duration";
        value = (frame.data[2].toInt() * 256.0) + frame.data[3].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "time_0-100";
        value = (frame.data[4].toInt() * 256.0) + frame.data[5].toInt();
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "time_0-75";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 752:
        topicName = "altitude";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) / 10.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gps_speed";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) / 100.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        // TODO verify
        topicName = "satellite";
        value = frame.data[4].toInt() & 1;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        // TODO verify
        topicName = "fix";
        value = frame.data[5].toInt() & 2;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gps_time";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 753:
        // TODO more details needed
        topicName = "latitude";
        // Here from high-level value of QJsonArray to a double is tricky.
        for (int i = 0; i < 4; i++) {
            framedata[i] = frame.data[i].toInt();
        }
        value = *(reinterpret_cast<const double*>(framedata.constData()));
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        // TODO more details needed
        topicName = "longitude";
        // Here from high-level value of QJsonArray to a double is tricky.
        for (int i = 0; i < 4; i++) {
            framedata[i] = frame.data[i].toInt();
        }
        value = *(reinterpret_cast<const double*>(framedata.constData()));
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 768:
        topicName = "rpm";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tps";
        value = (frame.data[2].toInt() * 100.0) / 255.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "map";
        value = (frame.data[4].toInt() * 256.0) + frame.data[5].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "lambda";
        value = (frame.data[6].toInt() * 256.0) + frame.data[7].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tc1";
        value = (((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 1470.0 / 65535.0) - 270.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 769:
        topicName = "derivata_farfalla";
        value = (frame.data[0].toInt() * 256.0) + frame.data[1].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "dmap";
        value = (frame.data[2].toInt() * 256.0) + frame.data[3].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tc2";
        value = (((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 1470.0 / 65535.0) - 270.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 770:
        topicName = "vhspeed";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 0.1;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "draxspeed";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 0.1;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "slip_calc";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 50.0 / 255.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "osasplip";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 0.25;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 772:
        topicName = "terogpianoquotato";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "terog";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "sabase";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 0.25;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "sa";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 0.25;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 774:
        topicName = "gear";
        value = frame.data[1].toInt();
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gear_shift_time_remain";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "poil";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "pfuel";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 775:
        topicName = "baro";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tc_pot";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "gear_pot";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 776:
        topicName = "vbattdir";
        value = ((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 18.0 / 1024.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "vbattkey";
        value = ((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 18.0 / 1024.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 777:
        topicName = "pbrake_front";
        value = ((frame.data[4].toInt() * 256.0) + frame.data[5].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "pbrake_rear";
        value = ((frame.data[6].toInt() * 256.0) + frame.data[7].toInt());
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        case 779:
        // TODO possibly topic name mismatch: th20 -> th2o
        topicName = "th20";
        value = (((frame.data[0].toInt() * 256.0) + frame.data[1].toInt()) * 160.0 / 65535.0) - 10.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "toil";
        value = (((frame.data[2].toInt() * 256.0) + frame.data[3].toInt()) * 160.0 / 65535.0) - 10.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tmp";
        value = (((frame.data[4].toInt() * 256.0) + frame.data[5].toInt()) * 160.0 / 65535.0) - 10.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});

        topicName = "tair";
        value = (((frame.data[6].toInt() * 256.0) + frame.data[7].toInt()) * 160.0 / 65535.0) - 10.0;
        //qInfo() << topicName << ": " << value;
        transceiver->publish(topicPrefix + topicName, {{"time", frame.time}, {"value", value}});
        break;

        default:
        //qInfo() << "No valid packet found! ID: " << frame.id.toInt();
        return;
    }
}

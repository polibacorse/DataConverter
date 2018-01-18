/*
 * DataConverter
 * Copyright (C) 2017  Poliba Corse and its members
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "DataConverter.h"
#include <json/json.h>
#include <sstream>
#include <math.h>
#include <iostream>
//#define DEBUG  //uncomment this line to allow verbose output

DataConverter::DataConverter() : mosqpp::mosquittopp()
{
	const char *host = "localhost";
	this->connect_async(host);
	this->loop_start();

}

DataConverter::~DataConverter()
{

	this->loop_stop();
	this->disconnect();
}

void DataConverter::on_connect(int rc)
{
	if (!rc)
		this->subscribe(NULL, "$SYS/raw");
}

void DataConverter::on_message(const struct mosquitto_message *message)
{
	const char *json = (char *)message->payload;

	this->Fmt(this->Cnvt_Json2CAN(json));
}

struct CANFrame DataConverter::Cnvt_Json2CAN(const char *jsonRaw)
{
	Json::Reader reader;
	Json::Value json;
	struct CANFrame frame = {};

	reader.parse(jsonRaw, json);

	frame.id = (short int)json["id"].asInt();
	frame.time = json["time"].asInt64();

	for (int i = 0; i < 8; i++)
		frame.data[i] = json["data"][i].asInt();

	return frame;
}

std::string DataConverter::Cnvt_Data2Json(const struct Data fmt)
{
	std::stringstream buf;

	buf << "{\"time\":" << fmt.time << ",\"value\":" << fmt.value << "}";

	return buf.str();
}

void DataConverter::Pub(std::string channel, const struct Data fmt)
{
	std::string json = Cnvt_Data2Json(fmt);
	this->publish(NULL, channel.c_str(), json.length(), json.c_str());

}

void DataConverter::Fmt(struct CANFrame frame)
{
	// axiliary val to eval payload
	double value;
	char *framedata;
	std::string channelPrefix("$SYS/formatted/");
	std::string channel, channelName, json;

	switch (frame.id) {
		case 747:
		channelName = "a1x";
		value = ((frame.data[0] * 3.0) / 255.0) - 1.5 + (frame.data[1] / 1000.0);


                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif



		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a2x";
		value = ((frame.data[2] * 3.0) / 255.0) - 1.5 + (frame.data[3] / 1000.0);


                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif




		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a3x";
		value = ((frame.data[4] * 3.0) / 255.0) - 1.5 + (frame.data[5] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a1y";
		value = ((frame.data[6] * 3.0) / 255.0) - 1.5 + (frame.data[7] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 748:
		channelName = "a2y";
		value = ((frame.data[0] * 3.0) / 255.0) - 1.5 + (frame.data[1] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a3y";
		value = ((frame.data[2] * 3.0) / 255.0) - 1.5 + (frame.data[3] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 749:
		channelName = "a1z";
		value = ((frame.data[0] * 3.0) / 255.0) - 1.5 + (frame.data[1] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a2z";
		value = ((frame.data[2] * 3.0) / 255.0) - 1.5 + (frame.data[3] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "a3z";
		value = ((frame.data[4] * 3.0) / 255.0) - 1.5 + (frame.data[5] / 1000.0);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 750:
		channelName = "slip_ok";
		value = frame.data[7];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "auto_acc_flag";
		value = (frame.data[0] & 128) / 128;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "debug_mode";
		value = (frame.data[0] & 64) / 64;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "datalog_on-off";
		value = (frame.data[0] & 32) / 32;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "telemetria_on-off";
		value = (frame.data[0] & 16) / 16;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "lap_close";
		value = frame.data[1];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 751:
		channelName = "target_rpm_up";
		value = (frame.data[0] * 256.0) + frame.data[1];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "shift_duration";
		value = (frame.data[2] * 256.0) + frame.data[3];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "time_0-100";
		value = (frame.data[4] * 256.0) + frame.data[5];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "time_0-75";
		value = (frame.data[6] * 256.0) + frame.data[7];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 752:
		channelName = "altitude";
		value = ((frame.data[0] * 256.0) + frame.data[1]) / 10.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "gps_speed";
		value = ((frame.data[2] * 256.0) + frame.data[3]) / 10.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "satellite";
		value = frame.data[4];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "fix";
		value = frame.data[5];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "gps_time";
		value = (frame.data[6] * 256.0) + frame.data[7];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 753:
		channelName = "latitude";
		framedata = frame.data;
		value = *((double*)framedata);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 754:
		channelName = "longitude";
		framedata = frame.data;
		value = *((double*)framedata);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 768:
		channelName = "rpm";
		value = (frame.data[0] * 256.0) + frame.data[1];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "tps";
		value = (frame.data[2] * 100.0) / 255.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "map";
		value = (frame.data[4] * 256.0) + frame.data[5];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "lambda";
		value = (frame.data[6] * 256.0) + frame.data[7];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 769:
		channelName = "derivata_farfalla";
		value = (frame.data[0] * 256.0) + frame.data[1];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "dmap";
		value = (frame.data[2] * 256.0) + frame.data[3];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 770:
		channelName = "vhspeed";
		value = ((frame.data[0] * 256.0) + frame.data[1]) * 0.1;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "draxspeed";
		value = ((frame.data[2] * 256.0) + frame.data[3]) * 0.1;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "slip_calc";
		value = ((frame.data[4] * 256.0) + frame.data[5]) * 50.0 / 255.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "osasplip";
		value = ((frame.data[6] * 256.0) + frame.data[7]) * 0.25;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 772:
		channelName = "terogpianoquotato";
		value = ((frame.data[0] * 256.0) + frame.data[1]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "terog";
		value = ((frame.data[2] * 256.0) + frame.data[3]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "sabase";
		value = ((frame.data[4] * 256.0) + frame.data[5]) * 0.25;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "sa";
		value = ((frame.data[6] * 256.0) + frame.data[7]) * 0.25;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 774:
		channelName = "gear";
		value = frame.data[1];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "gear_shift_time_remain";
		value = ((frame.data[2] * 256.0) + frame.data[3]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "poil";
		value = ((frame.data[4] * 256.0) + frame.data[5]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif


		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "pfuel";
		value = ((frame.data[6] * 256.0) + frame.data[7]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 775:
		channelName = "baro";
		value = ((frame.data[0] * 256.0) + frame.data[1]);

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "lnr3i";
		value = (frame.data[2] * 256.0) + frame.data[3];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "lnr4i";
		value = (frame.data[4] * 256.0) + frame.data[5];

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 776:
		channelName = "vbattdir";
		value = ((frame.data[0] * 256.0) + frame.data[1]) * 18.0 / 1024.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "vbattkey";
		value = ((frame.data[2] * 256.0) + frame.data[3]) * 18.0 / 1024.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;

		case 779:
		channelName = "th20";
		value = (((frame.data[0] * 256.0) + frame.data[1]) * 160.0 / 65535.0) - 10.0;

                 #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "toil";
		value = ((frame.data[2] * 256.0) + frame.data[3]) * 18.0 / 1024.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "tmp";
		value = ((frame.data[4] * 256.0) + frame.data[5]) * 18.0 / 1024.0;

                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});

		channelName = "tair";
		value = ((frame.data[6] * 256.0) + frame.data[7]) * 18.0 / 1024.0;
		
                #ifdef DEBUG
                std::cout<< channelName<<": " <<" "<<value << std::endl; // DEBUG PURPOSES
                #endif

		this->Pub(channelPrefix + channelName, {frame.time, value});
		break;
	}
}


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
#pragma once
#include <mosquittopp.h>
#include <string>

struct CANFrame {
	short int id;
	unsigned int time;
	char data[8];
};

struct Data {
	unsigned int time;
	double value;
};

class DataConverter : public mosqpp::mosquittopp {
public:
	/*
	 * Use async capability of mosquitto to improve multithreading
	 */
	DataConverter();
	~DataConverter();

	// Mosquitto interface callbacks
	void on_connect(int rc);
	void on_message(const struct mosquitto_message *message);

	struct CANFrame Cnvt_Json2CAN(const char *);
	std::string Cnvt_Data2Json(const struct Data);
	void Fmt(const struct CANFrame);
	void Pub(std::string, const struct Data);
};


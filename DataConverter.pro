TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle qt

LIBS += -lmosquitto -lmosquittopp -ljsoncpp

SOURCES += \
	main.cpp \
	DataConverter.cpp

HEADERS += \
	DataConverter.h

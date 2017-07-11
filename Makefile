INCLUDE=-I/usr/include/jsoncpp
LDLINK=-lmosquittopp -ljsoncpp

all: DataConverter

DataConverter: main.o DataConverter.o
	$(CROSS_COMPILE)$(CXX) -g -o DataConverter main.o DataConverter.o $(INCLUDE) $(LDLINK)

%.o: %.cpp
	$(CROSS_COMPILE)$(CXX) -g -c $< --std=c++11 $(INCLUDE) $(LDLINK)

clean:
	rm *.o DataConverter


all: DataConverter

DataConverter: main.o DataConverter.o
	$(CROSS_COMPILE)$(CXX) -g -o DataConverter main.o DataConverter.o -lmosquittopp -ljsoncpp

%.o: %.cpp
	$(CROSS_COMPILE)$(CXX) -g -c $< --std=c++11

clean:
	rm *.o DataConverter

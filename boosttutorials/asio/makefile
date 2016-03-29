CC=g++
INCLUDES=-I/usr/include/boost
CXXFLAGS=-c -Wall -std=c++11 -O6 $(INCLUDES)
LINKFLAGS=-lboost_system -lboost_thread
TARGET=timer5
OBJ=$(TARGET).o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(LINKFLAGS) $(OBJ)

$(TARGET).o: $(TARGET).cxx
	$(CC) $(CXXFLAGS) $(TARGET).cxx

clean:
	rm *.o $(TARGET)

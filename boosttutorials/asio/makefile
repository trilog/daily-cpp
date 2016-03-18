CC=g++
CXXFLAGS=-c -Wall -std=c++11 -O6 -lboost_system
LDFLAGS=-lboost_system
TARGET=timer3
OBJ=$(TARGET).o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

$(TARGET).o: $(TARGET).cxx
	$(CC) $(CXXFLAGS) $(TARGET).cxx

clean:
	rm *.o $(TARGET)

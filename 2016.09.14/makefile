CC=g++
CXXFLAGS=-c -Wall -std=c++11 -O6
TARGET=anadetector
OBJ=main.o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: main.cxx
	$(CC) $(CXXFLAGS) main.cxx

clean:
	rm *.o $(TARGET)

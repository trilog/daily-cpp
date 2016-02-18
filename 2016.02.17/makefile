CC=g++
CXXFLAGS=-c -Wall -std=c++11 -O6
TARGET=reversi
OBJ=main.o Board.o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: main.cxx
	$(CC) $(CXXFLAGS) main.cxx

Board.o: Board.h Board.cxx
	$(CC) $(CXXFLAGS) Board.cxx

clean:
	rm *.o $(TARGET)

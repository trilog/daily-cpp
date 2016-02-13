CC=g++
CXXFLAGS=-c -Wall -std=c++11 -O6
TARGET=Countdown
OBJ=main.o NumOp.o

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: main.cxx
	$(CC) $(CXXFLAGS) main.cxx

NumOp.o: NumOp.h NumOp.cxx
	$(CC) $(CXXFLAGS) NumOp.cxx

clean:
	rm *.o $(TARGET)

CC=g++
CFLAGS=-c -Wall
BUILD_DIR=build

all: what.a

what.a: $(BUILD_DIR)/main.o
	$(CC) $(BUILD_DIR)/main.o -o what.a

$(BUILD_DIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

clean:
	rm -rf *.o *.a

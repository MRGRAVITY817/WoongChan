CC = g++
CFLAGS = -W -Wall
TARGET = chainRule 
OBJECTS = condFunc.o loopFunc.o ynFunc.o main.o
MAKE = make

all: $(TARGET)
	./$^

$(TARGET) : 
	cd src && make

clean: 
	rm obj/*.o $(TARGET)

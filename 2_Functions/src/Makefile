CC = g++
CFLAGS = -W -Wall
TARGET = chainRule 
OBJECTS = condFunc.o loopFunc.o ynFunc.o main.o

all: $(TARGET)

$(TARGET) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^ && mv $@ ../ && mv *.o ../obj


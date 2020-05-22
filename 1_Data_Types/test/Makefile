CC = g++
CFLAGS = -W -Wall
TARGET = test

all: $(TARGET)
	./$^

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm $(TARGET) *.o


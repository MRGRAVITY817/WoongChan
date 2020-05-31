CC = g++
CFLAGS = -W -Wall
TARGET = main

all: $(TARGET)
	./$^

$(TARGET): $(TARGET).cpp
	$(CC) -o $@ $^

clean:
	rm $(TARGET)

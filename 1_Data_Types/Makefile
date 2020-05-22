CC = g++
CFLAGS = -W -Wall
TARGET = dataTypes

all: $(TARGET)
	./$^

$(TARGET) : $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).o : $(TARGET).cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	rm $(TARGET) *.o

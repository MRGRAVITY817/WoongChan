CC = g++
TARGET = main
CFLAGS = -W -Wall

all: $(TARGET)
	./$^

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(TARGET) *.o

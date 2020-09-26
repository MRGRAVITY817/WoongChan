CC = g++
TARGET = stack
CFLAGS = -W -Wall

all: $(TARGET)
	./$^

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(TARGET) *.o

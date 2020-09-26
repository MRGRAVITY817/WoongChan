CC = g++
CFLAGS = -W -Walls
TARGET = queue

all: $(TARGET)
	./$^

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(TARGET) *.o

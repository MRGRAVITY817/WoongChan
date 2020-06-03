CC = g++
CFLAGS = -W -Wall
TARGET = main
MAKE = make
OBJ = main.o

all: $(TARGET)
	./$^

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm $(TARGET) *.o

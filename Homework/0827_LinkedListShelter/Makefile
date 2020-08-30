CC = g++
CFLAGS = -W -Wall
TARGET = main
OBJS = main.o hw_shelter.o shelter.o people.o 

all: $(TARGET)
	./$^

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm *.o $(TARGET)
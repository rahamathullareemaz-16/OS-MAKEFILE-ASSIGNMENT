CC=gcc
CFLAGS=-Wall

TARGET=calculator
OBJS= main.o add.o sub.o mul.o div.o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
main.o:main.c calc.h
	$(CC) $(CFLAGS) -c main.c
add.o:add.c calc.h
	$(CC) $(CFLAGS) -c add.c
sub.o:sub.c calc.h
	$(CC) $(CFLAGS) -c sub.c
mul.o:mul.c calc.h
	$(CC) $(CFLAGS) -c mul.c
div.o:div.c calc.h
	$(CC) $(CFLAGS) -c div.c
clean:
	rm -f *.o $(TARGET)
	

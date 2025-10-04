CC=gcc
CFLAGS=-Wall -std=c11
TARGET=resolver

all: $(TARGET)

$(TARGET): main.o resolver.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o resolver.o

main.o: main.c resolver.h
	$(CC) $(CFLAGS) -c main.c

resolver.o: resolver.c resolver.h
	$(CC) $(CFLAGS) -c resolver.c

clean:
	rm -f *.o $(TARGET)

CC=gcc
CFLAGS=-c -O3 -std=c89

all:
	$(CC) $(CFLAGS) ./src/bbgpio.c
	ar -cvq libbbgpio.a *.o

clean:
	rm -f *.o
	rm -f libbbgpio.a
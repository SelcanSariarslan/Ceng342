CC=gcc
CFLAGS=-Wall

all: 18050151005

18050151005: 18050151005.c
	$(CC) $(CFLAGS) -o 18050151005 18050151005.c

clean:
	rm -f 18050151005


# Compiler and flags
CC     = cc
CFLAGS = -O3 -Wall -std=c2x -I.

# Default target
all: clean nm-naive

# Build the binary
nm-naive: nm-naive.o
	$(CC) $(CFLAGS) $^ -o $@

# Compile object file
nm-naive.o: nm-naive.c nm-naive.h netmap.h
	$(CC) $(CFLAGS) -c nm-naive.c -o nm-naive.o

# Cleanup
clean:
	rm -f *.o nm-naive

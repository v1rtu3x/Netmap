flags=-O3 -Wall -std=c2x
ldflags=/home/v1rtu3x/Netmap/nmutils/nmutils.o

all: clean nm-naive

nm-naive: nm-naive.o
	cc ${flags} $^ -o $@ ${ldflags}

nm-naive.o: nm-naive.c
	cc ${flags} -c $^ -o $@

clean:
	rm -f *.o nm-naive

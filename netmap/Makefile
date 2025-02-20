flags=-O3 -Wall -std=c2x
ldflags=

all: clean nm-naive

nm-naive: nm-naive.o
	 cc ${flags} $^ -o $@ ${ldflags}

nm-naive.o: nm-naive.c
	 cc ${flags} -c $^ -o $@ ${ldflags}

clean:
	 rm -f *.o nm-naive

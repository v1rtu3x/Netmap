flags=-O3 -Wall -std=c2x
ldflags=

all: clean nm-naive

nm-naive: nm-naive.O3
    cc ${flags} $^ -o $@ {ldflags}
nm-naive.o: nm-naive.c
    cc ${flags} -c $^ -o $@ {ldflags}

clean:
    remove *.o nm-naive
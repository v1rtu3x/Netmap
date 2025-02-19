flags=-O3 -Wall -std=c2x 
ldflags=-fPIC -shared -ldl -D_GNU_SOURCE
 
all: clean nmutils.so

nmutils.so: nmutils.o
    cc ${flags} $^ -o $@ ${ldflags}

nmutils.o: nmutils.c
    cc ${flags} -c $^ -o $@ ${ldflags}

clean:
    rm -f nmutils.o nmutils.so
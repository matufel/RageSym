CC=gcc
CFLAGS=-I.
DEPS = src/symbolicValues/ranges.h


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compile: src/symbolicValues/ranges.o src/symbolicValues/symbolicValues.o
	$(CC) -o target/compiled src/symbolicValues/ranges.o src/symbolicValues/symbolicValues.o 

CC=gcc
CFLAGS=-I.
DEPS = symbolicValues/ranges.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: symbolicValues/ranges.o symbolicValues/symbolicValues.o
	$(CC) -o target/compiled symbolicValues/ranges.o symbolicValues/symbolicValues.o 

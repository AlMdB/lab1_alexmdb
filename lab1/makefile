CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o adt_matrix.o adt_integral.o adt_string.o adt_base.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c adt_matrix.h adt_integral.h adt_string.h adt_base.h
	$(CC) $(CFLAGS) -c -o $@ $<

adt_matrix.o: adt_matrix.c adt_matrix.h adt_base.h
	$(CC) $(CFLAGS) -c -o $@ $<

adt_integral.o: adt_integral.c adt_integral.h adt_base.h
	$(CC) $(CFLAGS) -c -o $@ $<

adt_string.o: adt_string.c adt_string.h adt_base.h
	$(CC) $(CFLAGS) -c -o $@ $<

adt_base.o: adt_base.c adt_base.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o main

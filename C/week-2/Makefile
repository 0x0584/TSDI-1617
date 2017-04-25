CC = gcc
CFLAGS = -Wall
LDFLAGS = -I.
OBJ = lab1.o mem.o sort.o
DEPS = lab.h
EXEC = lab1

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

clean:
	rm -f *.o $(EXEC)

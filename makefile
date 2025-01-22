CC = gcc
CFLAGS = -Wall -g
OBJ = main.o io.o algoritmos.o

tp3: $(OBJ)
	$(CC) $(CFLAGS) -o tp3 $(OBJ)

main.o: main.c io.h algoritmos.h
	$(CC) $(CFLAGS) -c main.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c

algoritmos.o: algoritmos.c algoritmos.h
	$(CC) $(CFLAGS) -c algoritmos.c

clean:
	rm -f *.o tp3
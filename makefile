CC = gcc
CFLAGS = -Wall -g
OBJ = main.o io.o algoritmos.o time.o

tp3: $(OBJ)
	$(CC) $(CFLAGS) -o tp3 $(OBJ)

main.o: main.c io.h algoritmos.h time.h
	$(CC) $(CFLAGS) -c main.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c

algoritmos.o: algoritmos.c algoritmos.h
	$(CC) $(CFLAGS) -c algoritmos.c

time.o: time.c time.h
	$(CC) $(CFLAGS) -c time.c

clean:
	rm -f *.o tp3
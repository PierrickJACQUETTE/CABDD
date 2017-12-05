CC = gcc
CFLAGS = -Wall
EXEC  = TP8
HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(EXEC)

TP8: $(OBJECTS)
	rm -r ../data/tree
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	rm -r ../data/tree
	./TP8

clean:
	rm -f *.o

mrproper: clean
	rm -r ../data/tree
	rm -f $(EXEC)
	rm -f *.gch

CC = gcc
CFLAGS = -Wall
EXEC = main
HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(EXEC)

main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
	rm -f *.gch
	rm -fR R R0

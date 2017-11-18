CC = gcc
CFLAGS = -Wall
EXEC  = TP6
HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(EXEC)

TP6: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)
	mkdir -p RH R SH S RSH RS

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
	rm -f *.gch
	rm -fR RH R SH S RSH RS

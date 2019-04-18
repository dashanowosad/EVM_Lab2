# CC = compiler
CC=gcc
#CFLAGS	= flags for compiler
CFLAGS=-c -Wall

.PHONY: clean

all: test del

test: test.o msc.a
	$(CC) -o test  test.o -L. msc.a

msc.a: test.o Command.o Memory.o Register.o Visual.o Bigchar.o
	ar cr msc.a Command.o Memory.o Register.o Visual.o Bigchar.o
	
test.o: test.c
	$(CC) $(CFLAGS) test.c

command.o: Command.c
	$(CC) $(CFLAGS) Command.c

memory.o: Memory.c
	$(CC) $(CFLAGS) Memory.c

registr.o: Register.c
	$(CC) $(CFLAGS) Register.c

visual.o: Visual.c
	$(CC) $(CFLAGS) Visual.c

bigchar.o: Bigchar.c
	$(CC) $(CFLAGS) Bigchar.c
clean:
	rm -rf *.o *.a test
del: 
	rm -rf *.o

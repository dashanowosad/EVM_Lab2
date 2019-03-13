# CC = compiler
CC=gcc
#CFLAGS	= flags for compiler
CFLAGS=-c -Wall

.PHONY: clean

all: MSC del

MSC: test.o msc.a
	$(CC) -o MSC test.o -L. msc.a

msc.a: test.o Command.o Memory.o Register.o Visual.o
	ar cr msc.a Command.o Memory.o Register.o Visual.o
	
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

clean:
	rm -rf *.o *.a MSC
del: 
	rm -rf *.o

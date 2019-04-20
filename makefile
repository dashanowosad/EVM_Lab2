# CC = compiler
CC=gcc
#CFLAGS	= flags for compiler
CFLAGS=-c -Wall

.PHONY: clean

all: test.exe del

test.exe : main.o MSC/msc.a Bigchar/bc.a
	$(CC) -o test.exe  main.o -L. MSC/msc.a Bigchar/bc.a

MSC/msc.a:  MSC/Command.o MSC/Memory.o MSC/Register.o 
	ar cr MSC/msc.a MSC/Command.o MSC/Memory.o MSC/Register.o 

Bigchar/bc.a: Bigchar/Bigchar.o Visual/Visual.o
	ar cr Bigchar/bc.a Bigchar/Bigchar.o Visual/Visual.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

MSC/command.o: MSC/Command.c
	$(CC) $(CFLAGS) MSC/Command.c

MSC/memory.o: MSC/Memory.c
	$(CC) $(CFLAGS) MSC/Memory.c

MSC/registr.o: MSC/Register.c
	$(CC) $(CFLAGS) MSC/Register.c

Visual/visual.o: Visual/Visual.c
	$(CC) $(CFLAGS) Visual/Visual.c

Bigchar/bigchar.o: Bigchar/Bigchar.c
	$(CC) $(CFLAGS) Bigchar/Bigchar.c




clean:
	cd MSC/ && rm -rf *.o *.a
	cd Visual/ && rm -rf *.o
	cd Bigchar/ && rm -rf *.o *.a
	rm -rf *.o  *.exe
del:  
	cd MSC/ && rm -rf *.o 
	cd Visual/ && rm -rf *.o
	cd Bigchar/ && rm -rf *.o 
	rm -rf *.o


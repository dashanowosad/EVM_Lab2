# CC = compiler
CC=gcc
#CFLAGS	= flags for compiler
CFLAGS=-c -Wall

all: sat

sat: asembler.o
	$(CC) -Wall asembler.o -o sat 

asembler.o: asembler.c
	$(CC) $(CFLAGS) asembler.c 
clean:
	rm -rf *.o sat *.bin

	

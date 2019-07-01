# CC = compiler
CC=gcc
#CFLAGS	= flags for compiler
CFLAGS=-c -Wall

all: sbt

sbt: basic.o
	$(CC) -Wall basic.o -o sbt 

basic.o: basic.c
	$(CC) $(CFLAGS) basic.c 
clean:
	rm -rf *.o sbt as.txt

	

#ifndef _BASIC_
#define _BASIC_

#include <stdio.h>
#include <stdlib.h>


int CheckComand(char *S, int adress);
int END_function(int adress);
int INPUT_function(int adress);
int PRINT_function(int index);
int GOTO_function(int index);
int LET_function(int index);

char A[100];
int Adress[1000];
int Member[100];
int Jump[100];
FILE *f1, *f2;
#endif

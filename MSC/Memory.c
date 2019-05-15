#include <stdio.h>
#include "Mysimplecomputer.h"

int i;

int sc_memoryInit() {
    for(i = 0; i < N; i++)
		mass[i] = 0;
    return 0;
}

int sc_memorySet(int adress, int value) {
    if((adress < 0 ) || (adress > N)) {
		sc_regSet(M, 1);
		return -1; 
    }
    else {
		mass[adress] = value;
		return 0;
    }
}

int sc_memoryGet(int adress, int *value) {
    if ((adress < 0 ) || (adress > N)) {
		sc_regSet(M, 1);
		return -1; 
    }
    else {
		*value = mass[adress];
		return 0;
    }
}

int sc_memorySave(char *filename) {
    FILE *file = fopen(filename, "wb");
	if (file) {
		fwrite(mass, sizeof(int), N, file);
		fclose(file);
		return 0;
	}else
		return -1;
}

int sc_memoryLoad(char *filename) {
	FILE *file = fopen(filename, "rb");
	if (file) {
		fread(mass, sizeof(int), N, file);
		fclose(file);
		return 0;
	}else
		return -1;
}

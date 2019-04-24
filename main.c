#include "Mysimplecomputer.h"

#include "Visual/Visual.h"
#include "Bigchar/Bigchar.h"
#include <stdio.h>

int main(){
	int tmp, i, j, z;
	int A[2] = {0xFFC3C3FF, 0xFF030303};
	mt_clrscr();
	z = 3;
	mt_gotoXY(2, 2);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10;j++){
			sc_memorySet(i, 9999);
			sc_memoryGet(i, &tmp);
			printf("%4d ", tmp);
		}
		mt_gotoXY(z, 2);
		z++;
	}
	bc_box(1, 1, 11, 51);
	mt_gotoXY(1, 23);
	printf("Memory");
	bc_box(12, 1, 21, 46);
	bc_box(1, 52, 3, 72);
	mt_gotoXY(1, 57);
	printf("Accumulator");
	bc_box(4, 52, 6, 72);
	mt_gotoXY(4, 54);
        printf("InstructionCounter");
	bc_box(7, 52, 9, 72);
	mt_gotoXY(7, 58);
        printf("Operation");
	bc_box(10, 52, 12, 72);
	mt_gotoXY(10, 60);
        printf("Flags");
	bc_box(13, 47, 21, 72);
	mt_gotoXY(13, 48);
        printf("Keys:");
	mt_gotoXY(14, 48);
	printf("l  - load");
	mt_gotoXY(15, 48);
	printf("s  - save");
	mt_gotoXY(16, 48);
	printf("r  - run");
	mt_gotoXY(17, 48);
	printf("t  - step");
	mt_gotoXY(18, 48);
	printf("i  - reset");
	mt_gotoXY(19, 48);
	printf("F5 - accumulator");
	mt_gotoXY(20, 48);
	printf("F6 - instructionCounter");
	bc_printbigchar(A, 13, 2, 0, 7);
        bc_printbigchar(A, 13, 11, 0, 7);
        bc_printbigchar(A, 13, 20, 0, 7);
        bc_printbigchar(A, 13, 29, 0, 7);
        bc_printbigchar(A, 13, 38, 0, 7);
	mt_gotoXY(22, 1);
return 0;
}


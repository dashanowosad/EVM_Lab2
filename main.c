#include "Mysimplecomputer.h"

#include "Visual/Visual.h"
#include "Bigchar/Bigchar.h"
#include <stdio.h>
#include <stdlib.h>

/*void UI(void){
char s[5];
int tmp;
itoa(tmp,s,16);
}*/


int main(){
	int tmp, i, j, z, y = 2;
	char s[5];
	int A[2] = {0xFFC3C3FF, 0xFF030303};
	mt_clrscr();
	z = 3;
	mt_gotoXY(2, 2);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10;j++){
			sc_memorySet(i,4660);
			sc_memoryGet(i, &tmp);
			sprintf(s,"+%04x",tmp);
			printf("%s ",s);
		}
		mt_gotoXY(z, 2);
		z++;
	}
	bc_box(1, 1, 11, 61);
	mt_gotoXY(1, 29);
	printf("Memory");
	bc_box(12, 1, 21, 46);
	bc_box(1, 62, 3, 82);
	mt_gotoXY(1, 67);
	printf("Accumulator");
	bc_box(4, 62, 6, 82);
	mt_gotoXY(4, 64);
        printf("InstructionCounter");
	bc_box(7, 62, 9, 82);
	mt_gotoXY(7, 68);
        printf("Operation");
	bc_box(10, 62, 12, 82);
	mt_gotoXY(10, 70);
        printf("Flags");
	bc_box(13, 47, 21, 82);
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
	
	for (i = 0; i < 5; i++){
		bc_initbigchar(s[i],A);
		bc_printbigchar(A, 13, y, 0, 7);
		y += 9;
	}
	mt_gotoXY(22, 1);

return 0;
}


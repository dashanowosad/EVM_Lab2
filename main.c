#include "MSC/Mysimplecomputer.h"
#include "Visual/Visual.h"
#include "Bigchar/Bigchar.h"
#include "MRK/MyReadKey.h"

#include <stdio.h>


void UI(void){
	int tmp, i, j, z = 3, y = 2, c = 0;
	char s[6];
	int A[2] = {0x0, 0x0};
	mt_clrscr();
	mt_gotoXY(2, 2);
	sc_memoryLoad(swap);
	sc_memorySet(0,0x40FF);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10;j++){
			sc_memoryGet(c, &tmp);
			if(((tmp >> 14) & 0x1) == 0)
				sprintf(s, "+%04x", tmp);
			else{
				tmp = tmp & 0xFF;
				sprintf(s, "-%04x", tmp);
			}
			printf("%s ",s);
			c++;
		}
		mt_gotoXY(z, 2);
		z++;
	}
	bc_box(1, 1, 12, 61);
	mt_gotoXY(1, 29);
	printf("Memory");	
	
	bc_box(13, 1, 22, 46);

	for(i = 1; i < 11;i+=3)
		bc_box(i, 62, i+2, 82);
	mt_gotoXY(1, 67);
	printf("Accumulator");
	mt_gotoXY(2, 70);
	tmp = AC;
        if(((tmp >> 14) & 0x1) == 0)
		sprintf(s, "+%04x", tmp);
		else{
			tmp = tmp & 0xFF;
			sprintf(s, "-%04x", tmp);
                }
        printf("%s ",s);
	mt_gotoXY(4, 64);
        printf("InstructionCounter");
	mt_gotoXY(5,70);
	tmp = CR;
        if(((tmp >> 14) & 0x1) == 0)
                sprintf(s, "+%04x", tmp);
        printf("%s ",s);
	mt_gotoXY(7, 68);
        printf("Operation");
	mt_gotoXY(8, 68);
	printf("+ 00 : 00");
	mt_gotoXY(10, 70);
        printf("Flags");
	mt_gotoXY(11, 68 );
	printf(" O E V M");			
	bc_box(13, 47, 22, 82);
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
	
	sc_memoryGet(0, &tmp);
	if(((tmp >> 14) & 0x1) == 0)
		sprintf(s, "+%04x", tmp);
        else{
		tmp = tmp & 0xFF;
                sprintf(s, "-%04x", tmp);
	}
	for (i = 0; i < 5; i++){
		bc_initbigchar(s[i],A);
		bc_printbigchar(A, 14, y, 0, 7);
		y += 9;
	}
	mt_gotoXY(25, 1);
}


int main(){
	UI();
	return 0;
}


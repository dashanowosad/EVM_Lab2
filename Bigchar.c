#include "Mysimplecomputer.h"

int bc_printA(char * str){
	printf("\E(0");
	printf(str);
	printf("\E(B");
	return 0;
}


int bc_box (int x1, int y1, int x2, int y2){
	int i;
	printf("\E(0");
	mt_gotoXY(x1,y1);
	printf(ula);
	for (i = y1+1; i < y2; i++) printf(line);	
	//printf("Memory");	
	printf(ura);
	for (i = y1+1; i < y2; i++) {	
		mt_gotoXY(i,y2);	
		printf(vline);
		mt_gotoXY(i,x1);
		printf(vline);
	}
	mt_gotoXY(x2,y1);
	printf(dla);
	for (i = y1+1; i < y2; i++) printf(line);
	//mt_gotoXY(i+3,5);
	printf(dra);
	printf("\E(B");
	return 0;
}

int bc_printbigchar (int symbol[2], int x, int y, enum colors bgcolor, enum colors fgcolor) {
	mt_gotoXY(x, y);
	mt_setbgcolor(bgcolor);
	mt_setfgcolor(fgcolor);
	int i, j, z, tmp, tmpbyte,tmpbite;
	for(i = 0; i < 2; i++){
		tmp = symbol[i];
		for(j = 0; j <= 3; j++){
			tmpbyte = tmp & 255;
			for(z = 1; z <= 8; z++){
				tmpbite = (tmpbyte >> z) & 0x1;
				if(tmpbite == 0) 
					printf(" ");
				else
					bc_printA(ACS_CKBOARD);
			}
			tmp = tmp >> 8;
			mt_gotoXY(++x, y);
		}
	}
	int t,s;
	mt_getscreensize(&t,&s);
	mt_gotoXY(t,3);
	return 0;
}

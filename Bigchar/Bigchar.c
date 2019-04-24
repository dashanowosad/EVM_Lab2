#include "Bigchar.h"

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
	for (i = x1+1; i < x2; i++) {	
		mt_gotoXY(i,y2);	
		printf(vline);
		mt_gotoXY(i,y1);
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
	int i, j, z, tmp, tmpbyte,tmpbite;
	for(i = 0; i < 2; i++){
		tmp = symbol[i];
		for(j = 0; j <= 3; j++){
			tmpbyte = tmp & 255;
			for(z = 0; z <= 7; z++){
				tmpbite = (tmpbyte >> (7-z)) & 0x1;
				if(tmpbite){
					mt_setfgcolor(fgcolor);
					bc_printA(ACS_CKBOARD);					
				}
				else
					printf(" ");
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

int bc_setbigcharpos (int * big, int x, int y, int value){
	if((x >= 0) && (7 >= x)){
		if(value == 1){
			big[x / 4] = big[x / 4] | ((1 << (x * 8 + y)));
			//printf("%d",big[x / 4]);
		}else{
			big[x / 4] = big[x / 4] & (~(1 << (x * 8 + y)));
			//printf("%d",big[x / 4]);
		}return 0;
	}else
		return -1;

}

int bc_getbigcharpos (int * big, int x, int y, int * value){
        if((x >= 0) && (7 >= x)){
                *value = (big [x / 4] >> (x * 8 + y)) & 0x1;
		return 0;
        }else
                return -1;
}


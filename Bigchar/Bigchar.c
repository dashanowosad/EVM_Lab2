#include "Bigchar.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h> 

int  bc_initbigchar(char s, int *A){
	switch(s){
		case '+': {
			A[0] = 0xFF181818;
			A[1] = 0x181818FF;
			break;
		}
		case '-': {
                        A[0] = 0xFF000000;
                        A[1] = 0xFF;
                        break;
                }
		case '0': {
                        A[0] =0xC3C3C3FF;
                        A[1] =0xFFC3C3C3;
                        break;
                }
		case '1': {
                        A[0] =0x303030F;
                        A[1] =0x3030303;
                        break;
                }
		case '2': {
                        A[0] =0xFF0303FF;
                        A[1] =0xFFC0C0C0;
                        break;
                }
		case '3': {
                        A[0] =0xFF0303FF;
                        A[1] =0xFF030303;
                        break;
                }
		case '4': {
                        A[0] =0xC3C3C300; 
                        A[1] =0x30303FF;
                        break;
                }
		case '5': {
                        A[0] =0xFFC0C0FF;
                        A[1] =0xFF030303;
                        break;
                }
		case '6': {
                        A[0] =0xFFC0C0FF;
                        A[1] =0xFFC3C3C3;
                        break;
                }
		case '7': {
                        A[0] =0x303C3FF;
                        A[1] =0x3030303;
                        break;
                }
		case '8': {
                        A[0] =0xFFC3C3FF;
                        A[1] =0xFFC3C3C3;
                        break;
                }
		case '9': {
                        A[0] =0xFFC3C3FF;
                        A[1] =0xFF030303;
                        break;
              	}
		case 'a': {
                        A[0] =0xC3C3C3FF;
                        A[1] =0xC3C3C3FF;
                        break;
                }
		case 'b': {
                        A[0] =0xFEC3C3FE;	
                        A[1] =0xFEC3C3C3;
                        break;
                }
		case 'c': {
                        A[0] =0xC0C0C0FF;
                        A[1] =0xFFC0C0C0;
                        break;
                }
		case 'd': {
                        A[0] =0xC3C3C3FE;
                        A[1] =0xFEC3C3C3;
                        break;
                }
		case 'e': {
                        A[0] =0xFFC0C0FF;
                        A[1] =0xFFC0C0C0;
                        break;
                }
		case 'f': {
                        A[0] =0xFFC0C0FF;
                        A[1] =0xC0C0C0C0;
                        break;
                }
		default:{
			return -1;
		}

	}
	return 0;
}

int bc_printA(char * str){
	printf(S_tab);
	printf("%s", str);
	printf(F_tab);
	return 0;
}


int bc_box (int x1, int y1, int x2, int y2){
	int i;
	printf(S_tab);
	mt_gotoXY(x1,y1);
	printf(ula);
	for (i = y1+1; i < y2; i++) printf(line);
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
	printf(dra);
	printf(F_tab);
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
		}else{
			big[x / 4] = big[x / 4] & (~(1 << (x * 8 + y)));
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

int bc_bigcharwrite(int fd, int *big, int count) {
	if (fd != -1) {
		if (BC_SIZE == 0 || BC_SIZE < 0) BC_SIZE = 2;
		if (write(fd, big, count * BC_SIZE) == count * BC_SIZE) return 0;
		return -1;
	}
	return -1;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count) {
	if (fd != -1) {
		if (BC_SIZE == 0 || BC_SIZE < 0) BC_SIZE = 2;
		*count = read(fd, big, need_count * BC_SIZE);
		return 0;
	}
	return -1;
}

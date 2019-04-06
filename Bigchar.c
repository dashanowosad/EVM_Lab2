#include "Mysimplecomputer.h"

int bc_printA(char * str){
	printf("\E(0");
	printf("%s",str);
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
	/*mt_gotoXY(i+3,5);
	printf(dla);
	for (i = 0; i < cols/2 + 6; i++) printf(line);
	printf(dra);*/
	printf("\E(B");
	return 0;
}

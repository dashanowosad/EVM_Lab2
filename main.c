#include "MSC/Mysimplecomputer.h"
#include "Visual/Visual.h"
#include "Bigchar/Bigchar.h"
#include "MRK/MyReadKey.h"
#include "Control/Control.h"

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void timer(){
	if(CU() == -1){
		alarm(0);
		key = NONE;
	}
}
void reset(void){
	sc_memoryInit();
	AC = 0;
	CR = 0;
}




void printCandO(){
	int tmp, operand, command;
	char com[2], op[2];
	sc_memoryGet(CR, &tmp);
	printf("              ");
	mt_gotoXY(8, 68);
	if(sc_commandDecode(tmp, &command, &operand) == 0){
		sprintf(com, "%01x", command);
		printf(" %s :",com);
		sprintf(op, "%0x", operand);
		printf(" %s", op);
		
	}else
		printf("+ 00 : 00");
		
}


void UI(void){
	int tmp, i, j, z = 3, y = 2, c = 0;
	char s[6];
	int A[2] = {0x0, 0x0};
	mt_gotoXY(2, 2);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			sc_memoryGet(c, &tmp);
			if(((tmp >> 15) & 0x1) == 0)
				sprintf(s, "+%04x", tmp);
			else{
				tmp = tmp & 0x7FFF;
				sprintf(s, "-%04x", tmp);
			}
			printf("%s ", s);
			c++;
		}
		mt_gotoXY(z, 2);
		z++;
	}
	bc_box(1, 1, 12, 61);
	mt_gotoXY(1, 29);
	printf("Memory");	
	bc_box(13, 1, 23, 46);
	for(i = 1; i < 11; i += 3)
		bc_box(i, 62, i+2, 82);
	mt_gotoXY(1, 67);
	printf("Accumulator");
	mt_gotoXY(2, 70);
	tmp = AC;
        if(((tmp >> 15) & 0x1) == 0)
			sprintf(s, "+%04x", tmp);
		else {
			tmp = tmp & 0x7FFF;
			sprintf(s, "-%04x", tmp);
		}
	printf("%s ", s);
	mt_gotoXY(4, 64);
	printf("InstructionCounter");
	mt_gotoXY(5, 70);
	tmp = CR;
	if(((tmp >> 15) & 0x1) == 0)
		sprintf(s, "+%04x", tmp);
    printf("%s ", s);
	mt_gotoXY(7, 68);
    printf("Operation");
	mt_gotoXY(8, 68);
	printCandO(); //////////ДОДЕЛАТЬ
	mt_gotoXY(10, 70);
    printf("Flags");
	mt_gotoXY(11, 68 );
	//printf(" O E V M");			
	bc_box(13, 47, 23, 82);
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
	printf("q  - exit");
	mt_gotoXY(20, 48);
	printf("w  - set the value");
	mt_gotoXY(21, 48);
	printf("F5 - accumulator");
	mt_gotoXY(22, 48);
	printf("F6 - instructionCounter");
	bc_box(24, 1, 26, 48);	
	mt_gotoXY(24, 19);
    printf("Input/Output");	
	sc_memoryGet(CR, &tmp);
	if(((tmp >> 15) & 0x1) == 0)
		sprintf(s, "+%04x", tmp);
    else {
		tmp &= 0x7FFF;
		sprintf(s, "-%04x", tmp);
	}
	for (i = 0; i < 5; i++) {
		bc_initbigchar(s[i], A);
		bc_printbigchar(A, 14, y, 8, 7);
		y += 9;
	}
	mt_gotoXY(25, 1);
}

int console(void) {
	char filename[80];
	char z[6];
	int flag = 1;
	int tmp;
	signal(SIGALRM, timer);
	signal(SIGUSR1, reset);
    rk_mytermsave();
	while(flag) {
		UI();
		CheckFlags();
        rk_mytermregime(0, 1, 1, 0, 0);
		printf(inv);
		fflush(stdout);
		mt_setbgcolor(1);
		fflush(stdout);
		mt_gotoXY((CR / 10) + 2, (CR % 10) * 6 + 2);
		fflush(stdout);
		sc_memoryGet(CR, &tmp);
		if(((tmp >> 15) & 0x1) == 0) {
			sprintf(z, "+%04x", tmp);
			fflush(stdout);
		} else {
			tmp &= 0x7FFF;
            sprintf(z, "-%04x", tmp);
			fflush(stdout);
		}
		printf("%s", z);
		fflush(stdout);
		mt_setbgcolor(8);
        fflush(stdout);
    	if (key != r) rk_readkey(&key);
		switch(key) {
			case F5: {
				rk_mytermrestore();
				mt_gotoXY(25, 2);
				printf("Enter AC value: ");
				scanf("%d", &AC);
				mt_gotoXY(25, 2);
				printf("                                            ");
				rk_mytermregime(0, 1, 1, 0, 0);
				break;
			}
			case F6: {
            	rk_mytermrestore();
				mt_gotoXY(25, 2);
				printf("Enter RC value: ");
				scanf("%d", &CR);
				mt_gotoXY(25, 2);
				printf("                                            ");
                rk_mytermregime(0, 1, 1, 0, 0);
                break;
			}
			case q: {
				flag = 0;
				rk_mytermrestore();
				mt_gotoXY(27, 1);
				break;	
			}
			case l: {
				rk_mytermrestore();
				mt_gotoXY(25, 2);
				printf("Enter filename: ");
				scanf("%s", filename);
				mt_gotoXY(25, 2);
				printf("                                           ");
				sc_memoryLoad(filename);
				rk_mytermregime(0, 1, 1, 0 ,0);
				break;
			}

			case s: {
				rk_mytermrestore();
				mt_gotoXY(25, 2);
				printf("Enter filename: ");
				scanf("%s", filename);
				mt_gotoXY(25, 2);
				printf("                                           ");
				sc_memorySave(filename);
				rk_mytermregime(0, 1, 1, 0 ,0);
				break;
			}
			case i: {
				raise(SIGUSR1);
				break;
			}
			case w: {
				rk_mytermrestore();
				mt_gotoXY(25, 2);
				printf("Enter cell  value: ");
				scanf("%d", &tmp);
				mt_gotoXY(25, 2);
				printf("                                           ");
				sc_memorySet(CR, tmp);
				rk_mytermregime(0, 1, 1, 0, 0);
				break;
			}
			case r: {
				F_reg = 0;
				alarm(1);
				break;		
			}
			case t: {
				CU();
				sc_regSet(T, 0);
				rk_mytermrestore();
				CheckFlags();
				rk_mytermregime(0, 1, 1, 0, 0);
				break;
			}
			case DOWN: {
				if(CR + 10 < 100)
					CR += 10;
				break;
			}
			case UP: {
				if(CR - 10 >= 0)
					CR -= 10;
				break;
			}
			case LEFT: {
				if(CR - 1 >= 0)
					CR--;
				break;
			}
			case RIGHT: {
				if(CR + 1 < 100)
					CR++;
				break;
			}
			case NONE: {
				break;		
			}
			default: {
				break;
	        }
		}
		if (key == r)
			pause();
		rk_mytermrestore();
	}
	return 0;
}

int main() {
	mt_clrscr();
	console();
	return 0;
}


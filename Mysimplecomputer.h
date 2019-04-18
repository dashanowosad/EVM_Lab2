#ifndef _MYSIMPLECOMPUTER_
#define _MYSIMPLECOMPUTER_

#include "Const.h"
#include "Flagmask.h"
#include "Commands.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>


extern int F_reg;
extern int mass[N];
extern int rows;
extern int cols;

	/*Memory Function*/
int sc_memoryInit(void);
int sc_memorySet(int adress, int value);
int sc_memoryGet(int adress, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char *filename);
	/*Memory end*/
	
	/*FLAGS register Function*/
int sc_regInit(void);
int sc_regSet(int flag, int value);
int sc_regGet(int flag, int * value);
	/*FLAGS end*/

	/*Ñommand processing functions*/
int checkCommand(int command);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);
	/*Ñommand processing end*/


	/*Visual*/
int mt_clrscr(void);
int mt_gotoXY(int X,int Y);
int mt_getscreensize(int *rows,int *cols);
int mt_setfgcolor(enum colors);
int mt_setbgcolor(enum colors);
	/*Visual*/	
	/*BigChar*/
int bc_printA(char * str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int[2], int x, int y, enum colors bgcolor, enum colors fgcolor);
int bc_setbigcharpos(int* big, int x, int y, int value);
int bc_getbigcharpos(int * big, int x, int y, int * value);
int bc_bigcharwrite(int fd, int * big, int count);
int bc_bigcharread(int fd, int * big, int need_count, int count);
	/*BigChar*/

#endif //_MYSIMPLECOMPUTER_

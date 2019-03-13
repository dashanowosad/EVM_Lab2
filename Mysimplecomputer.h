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
enum colors {Dark, Red, Green, Yellow, Dark_Blue, Purple, Blue, White, Standart};
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

#endif //_MYSIMPLECOMPUTER_

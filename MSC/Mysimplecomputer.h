#ifndef _MYSIMPLECOMPUTER_
#define _MYSIMPLECOMPUTER_

#include "../Const.h"
#include "Flagmask.h"
#include "Commands.h"


int F_reg;
int AC;
int CR;
int mass[N];
int rows;
int cols;

	/*Memory Function*/
int sc_memoryInit(void);
int sc_memorySet(int adress, int value);
int sc_memoryGet(int adress, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
	/*Memory end*/
	
	/*FLAGS register Function*/
int sc_regInit(void);
int sc_regSet(int flag, int value);
int sc_regGet(int flag, int *value);
	/*FLAGS end*/

	/*Command processing functions*/
int checkCommand(int command);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);
	/*Command processing functions*/

#endif //_MYSIMPLECOMPUTER_

#ifndef _CPU_
#define _CPU_
#include "../MRK/MyReadKey.h"

int CU();
int ALU(int command, int operand);
void CheckFlags(void);

enum keys key;
#endif 

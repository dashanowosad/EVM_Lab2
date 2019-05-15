#include "Mysimplecomputer.h"


int sc_regInit(void) {
	F_reg = F_reg & 0;
	AC = 0;//kostil
	CR = 0;//kostil
	return 0;
}

int sc_regSet(int flag, int value) {
	if((flag > 0) || (flag < 31)) {
		if(value == 0) {
			F_reg = F_reg & (~(1 << flag));
			return 0;
		}else if (value == 1) {
			F_reg = F_reg | (1 << flag);
			return 0;
		} else 
			return 1; 
	}else 
		return -1;
}

int sc_regGet(int flag, int *value) {
	if ((flag > 0) || (flag < 31)) {
		*value = (F_reg >> flag) & 0x1;
		return 0;
	}else
		return -1;
}

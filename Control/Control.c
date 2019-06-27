#include "Signal.h"


int ALU(int command, int operand) {
	int value;
	if (sc_memoryGet(operand, &value) == -1)
	{
		sc_regSet(M, 1);
		return -1;
	}
	switch(command)
	{
		case ADD:
			AC += value;
			if (Accumulator > 32767 || Accumulator < -32767)
				return -1;
			break;
		case SUB:
			AC -= value;
			if (Accumulator > 32767 || Accumulator < -32767)
				return -1;
			break;
		case MUL:
			AC *= value;
			if (Accumulator > 32767 || Accumulator < -32767)
				return -1;

			break;
		case DIVIDE:
			if (value == 0)	{
				sc_regSet(DEL, 1);
				return -1;
			}
			AC /= value;
			break;
		default:
			return -1;
	}
	return 0;
}


int CU(){
	


}

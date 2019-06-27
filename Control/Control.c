#include "Signal.h"


int ALU(int command, int operand) {
	int value;
	if (sc_memoryGet(operand, &value) == -1){
		sc_regSet(M, 1);
		return -1;
	}
	switch(command){
		case ADD:
			AC += value;
			if (Accumulator > 32767 || Accumulator < -32767){
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
	int operand, command, value;
	sc_memoryGet(CR, &value);
	if (!sc_commandDecode(value, &command, &operand)) {
		sc_regSet(FlagIncorrectCommand, 1);
		return -1;
	}
	if (command >= 0x30 && command <= 0x33){
		if(ALU(command, operand) == 0)
			return 0;
		else
			return -1;
	}else{
		switch(command){
			case READ:{
			}
			case WRITE:{
			}
			case LOAD:{
				sc_MemoryGet(operand, &value);
				value &= 0x7FFF;
				AC=value;
				break;
			}
			case STORE:{
				sc_MemorySet(operand, AC);
				break;
			}
			case JUMP:{
				CR=operand;
			}	
			case JNEG:{
				if(AC<0)
					CR=operand;

			}
			case JZ:{
			}
			case HALT:{
			}

	}
	


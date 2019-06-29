#include "../MSC/Mysimplecomputer.h"
#include "Control.h"
#include "signal.h"


int ALU(int command, int operand) {
	int value;
	if (sc_memoryGet(operand, &value) == -1){
		sc_regSet(M, 1);
		return -1;
	}
	value &= 0x7FFF;
	switch(command){
		case ADD:{
			AC += value;
			if (AC > 32767 || AC < -32767)
				return -1;
			CR++;
			break;
		}
		case SUB:{
			AC -= value;
			if (AC > 32767 || AC < -32767)
				return -1;
			CR++;
			break;
		}
		case MUL:{
			AC *= value;
			if (AC > 32767 || AC < -32767)
				return -1;
			CR++;
			break;
		}
		case DIVIDE:{
			if (value == 0)	{
				sc_regSet(DEL, 1);
				return -1;
			}
			AC /= value;
			CR++;
			break;
		}
		default:{
			return -1;
		}
	}
	return 0;
}


int CU(){
	int operand, command, value;
	sc_memoryGet(CR, &value);
	if (sc_commandDecode(value, &command, &operand)==-1) {
		sc_regSet(E, 1);
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
				sc_memoryGet(operand, &value);
				value &= 0x3FFF;
				AC=value;
				CR++;
				break;
			}
			case STORE:{
				sc_memorySet(operand, AC);
				CR++;
				break;
			}
			case JUMP:{
				CR=operand;
				break;
			}	
			case JNEG:{
				if(AC < 0)
					CR = operand;
				break;
			}
			case JZ:{
				if (AC == 0)
					CR = operand;
				else
					CR++;
				break;
			}
			case JNP:{
				if (AC % 2)
					CR = operand;
				else
					CR++;
				break;
			}
			case RCL:{
				if (AC>>31==0)
					AC = ((AC << operand) | (AC >> (31 - operand)) & (~(1 << 31)));
				else
    				AC = ((AC << operand) | (AC >> (31 - operand)) | (1 << 31));
					//AC = (AC << operand) | (unsigned()AC) >>  (32 - operand));
					CR++;
				break;
			}
			case HALT:{
				alarm(0);
				key = UP;
				break;
			}
			default:{
				break;			
			}
		}	
	
	}
	return 0;
}


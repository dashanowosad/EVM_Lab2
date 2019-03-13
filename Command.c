#include "Mysimplecomputer.h"

int checkCommand(int command){
	if( 
		command == READ   ||	command == WRITE  ||
		command == LOAD   ||	command == STORE  ||
		command == ADD    ||	command == SUB    ||
		command == DIVIDE ||	command == MUL    ||
		command == JUMP   ||	command == JNEG   ||
		command == JZ     ||	command == HALT   ||
		command == NOT    ||	command == AND    ||
		command == OR     ||	command == XOR    ||
		command == JNS    ||	command == JC     ||
		command == JNC    ||	command == JP     ||
		command == JNP    ||	command == CHL    ||
		command == SHR    ||	command == RCL    ||
		command == RCR    ||	command == NEG    ||
		command == ADDC   ||	command == SUBC   ||
		command == LOGLC  ||	command == LOGRC  ||
		command == RCCL   ||	command == RCCR   ||
		command == MOVA   ||	command == MOVR   ||
		command == MOVCA  ||	command == MOVCR   
	)
		return 0;
	else {
		sc_regSet(WC,1);
		return WC;
        }
}
int sc_commandEncode(int command, int operand, int * value){
	if(operand < 128){
		if (!checkCommand(command)){
		*(value) = *(value) & 0x0;
		*(value) = *(value) | command;
		*(value) = *(value) << 7;
		*(value) = *(value) | operand;
		return 0;
}
	else
		return 1;
	}
	sc_regSet(WO,1);
	return WO;
}
int sc_commandDecode(int value, int * command, int * operand){
	if(value >> 14 == 0){
		*(operand) = value & 0x7F;
		value = value >> 7;
		*(command) = value & 0x7F;
		if (!checkCommand(*command)){
			return 0;			
		}	
		return 1;
	}
	sc_regSet(WC, 1);
	return WC;
}

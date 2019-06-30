#include "Mysimplecomputer.h"

int checkCommand(int command) {
	if(
		command == READ   ||	command == WRITE  ||
		command == LOAD   ||	command == STORE  ||
		command == ADD    ||	command == SUB    ||
		command == DIVIDE ||	command == MUL    ||
		command == JUMP   ||	command == JNEG   ||
		command == JZ     ||	command == HALT   ||
		command == JNP    
	)
		return 0;
	else {
		sc_regSet(E, 1);
		return -1;
	}
}

int sc_commandEncode(int command, int operand, int *value) {
	if(operand < 128) {
		if (!checkCommand(command)) {
		*(value) = *(value) & 0x0;
		*(value) = *(value) | command;
		*(value) = *(value) << 8;
		*(value) = *(value) | operand;
		return 0;
		}
	else
		return -1;
	}
	return -1;
}

int sc_commandDecode(int value, int *command, int *operand) {
	if(value >> 15 == 0) {
		*(operand) = value & 0x7F;
//		value = value >> 8;
		*(command) = (value >> 8) & 0x7F;
		if (!checkCommand(*command)) {
			return 0;			
		}return -1;
	}
	return -1;
}

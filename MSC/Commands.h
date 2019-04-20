#ifndef _COMMAND_
#define _COMMAND_

enum {
		/*I/O*/
	READ   = 0x10,
	WRITE  = 0x11,
		/*Loading/overloading in accum*/
	LOAD   = 0x20,
	STORE  = 0x21,
		/*Arithmethic operations*/
	ADD    = 0x30,
	SUB    = 0x31,
	DIVIDE = 0x32,
	MUL    = 0x33,
		/*R*/
	JUMP   = 0x40,
	JNEG   = 0x41,
	JZ     = 0x42,
	HALT   = 0x43,
		/*User operations*/
	NOT    = 0x51,
	AND    = 0x52,
	OR     = 0x53,
	XOR    = 0x54,
	JNS    = 0x55,
	JC     = 0x56,
	JNC    = 0x57,
	JP     = 0x58,
	JNP    = 0x59,
	CHL    = 0x60,
	SHR    = 0x61,
	RCL    = 0x62,
	RCR    = 0x63,
	NEG    = 0x64,
	ADDC   = 0x65,
	SUBC   = 0x66,
	LOGLC  = 0x67,
	LOGRC  = 0x68,
	RCCL   = 0x69,
	RCCR   = 0x70,
	MOVA   = 0x71,
	MOVR   = 0x72,
	MOVCA  = 0x73,
	MOVCR  = 0x74
};

#endif //_COMMAND_

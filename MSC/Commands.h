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
	JNP    = 0x59,
};

#endif //_COMMAND_

#include "Mysimplecomputer.h"
#include <stdio.h>

int main(){
	int tmp, commandtest,c , o,i;
	sc_memoryInit();
	sc_regInit();
	printf("Setting cell 30 value 45\n");
	sc_memorySet(30, 45);
	printf("Getting cell value 30 \n");
	sc_memoryGet(30, &tmp);
	printf("%d ", tmp);
	printf("\n Filling memory with an increasing sequence and writing to a file \n");
	for(i = 0; i < N; i++){
		sc_memorySet(i, i);
		sc_memoryGet(i, &tmp);
		printf("%d ", tmp);
	}
	sc_memorySave("memory.bin");
	printf("\n Reinitialize RAM and read it from file \n");
	sc_memoryInit();
	printf("Reinitialized RAM \n");
	for(i = 0; i < N; i++){
		sc_memoryGet(i, &tmp);
                printf("%d ", tmp);
	}
	printf("\n RAM after reading from file \n");
	sc_memoryLoad("memory.bin");
	for(i = 0; i < N; i++){
		sc_memoryGet(i, &tmp);
		printf("%d ", tmp);
	}
	printf("\n Checking the operation of the outgoing memory flag \n");
	sc_memorySet(1213, 45);
	sc_regGet(AOF, &tmp);
	printf("Flag = %d", tmp);
	sc_regSet(AOF, 0);
	printf("\n Checking the command endecode function \n");
	printf("%d ",sc_commandEncode(SUB, 99, &commandtest));
	printf("\n Checking the command decode function \n");
	sc_commandDecode(commandtest, &c, &o);
	printf("\n Command = %d, Operand = %d \n", c, o);
	sc_commandEncode(1, 234567890,&commandtest);
	sc_commandDecode(commandtest, &c, &o);
        printf("\n Command = %d, Operand = %d \n", c, o);
	sc_commandEncode(2, 234567890,&commandtest);
        sc_commandDecode(commandtest, &c, &o);
        printf("\n Command = %d, Operand = %d \n", c, o);
	return 0;
}

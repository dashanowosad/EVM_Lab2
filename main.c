#include "Mysimplecomputer.h"

#include "Visual/Visual.h"
#include "Bigchar/Bigchar.h"
#include <stdio.h>

int main(){
	int tmp, commandtest,c , o,i, j, z=0;
	 int A[2] = {0x3033F00, 0x3F30303F}, u;
	/*sc_memoryInit();
	sc_regInit();
	printf("Setting cell 30 value 45\n");
	sc_memorySet(30, 45);
	printf("Getting cell value 30 \n");
	sc_memoryGet(30, &tmp);
	printf("%d ", tmp);*/
//	printf("\n Filling memory with an increasing sequence and writing to a file \n");
	mt_clrscr();
//	mt_gotoXY(2,2);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10;j++){
			sc_memorySet(i, z);
			sc_memoryGet(i, &tmp);
			printf("%4d ", tmp);
			z++;
		}
		printf("\n");
	}
	bc_box(1,1,11,51);
	mt_gotoXY(1,23);
	printf("Memory");
	bc_box(12,1,21,47);
	bc_printbigchar(A,13,2,0,7);
	bc_printbigchar(A,13,11,0,7);
	bc_printbigchar(A,13,20,0,7);
	bc_printbigchar(A,13,29,0,7);
	bc_printbigchar(A,13,38,0,7);
	/*
	sc_memorySave("Files/swap.bin");
	printf("\n Reinitialize RAM and read it from file \n");
	sc_memoryInit();
	printf("Reinitialized RAM \n");
	for(i = 0; i < N; i++){
		sc_memoryGet(i, &tmp);
                printf("%d ", tmp);
	}
	printf("\n RAM after reading from file \n");
	sc_memoryLoad("Files/swap.bin");
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
	

	mt_clrscr();
	bc_box(1,1,20,20);
	bc_printbigchar(A, 2, 25, 0, 7);
	bc_setbigcharpos(A, 0, 0, 0);
	bc_printbigchar(A, 20, 25, 0, 7);
	bc_getbigcharpos(A, 4, 0, &u);
	printf("%d",u);
	mt_setbgcolor(10);
*/
return 0;
}


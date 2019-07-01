#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CheckComand(char *S){
	if(strcmp(S,"READ") == 0) return 0x10;
	else if(strcmp(S,"WRITE") == 0) return 0x11;
	else if(strcmp(S,"LOAD") == 0) return 0x20;
	else if(strcmp(S,"STORE") == 0) return 0x21;
	else if(strcmp(S,"ADD") == 0) return 0x30;
	else if(strcmp(S,"SUB") == 0) return 0x31;
	else if(strcmp(S,"DIVIDE") == 0) return 0x32;
	else if(strcmp(S,"MUL") == 0) return 0x33;
	else if(strcmp(S,"JUMP") == 0) return 0x40;
	else if(strcmp(S,"JNEG") == 0) return 0x41;
	else if(strcmp(S,"JZ") == 0) return 0x42;
	else if(strcmp(S,"HALT") == 0) return 0x43;
	else if(strcmp(S,"JNP") == 0) return 0x59;
	else return -1;
}



int main(){
	FILE *f1, *f2;
	f1 = fopen("factorial.txt","r");
	f2 = fopen("factorial.bin", "wb");
	int A[100], adr,com, op, i, res;
	char adress[3], command[10], operand[3], result[10];
	char space; //для пробела
	for(i = 0; i < 100; i++)
		A[i] = 0;	
	if (f1) {
		while(!feof(f1)) {
			fscanf(f1,"%s",&adress);
			adr = atof(adress); //получили адрес ячейки
			fscanf(f1, "%c",&space);
			fscanf(f1,"%s",&command);
			if (CheckComand(command) != -1) { //если у нас команда
				com = CheckComand(command); //получили команду в 10-й системе счисления
				fscanf(f1, "%c",&space);
				fscanf(f1,"%s", &operand);
				op = atof(operand);//получили операнд (адрес новой ячейки)
				fscanf(f1, "%c",&space);
				res = com;
				res = res << 8;
				res |= op;
				A[adr] = res; 
			}else if(strcmp(command, "=") == 0){
					fscanf(f1, "%c",&space);
					fscanf(f1, "%s",&command);
					com = atof(command);
					A[adr] = com;
			}			
		}
		fclose(f1);
	} else 
		return -1;
	if(f2) {
		fwrite(A, sizeof(int), 100, f2);
		fclose(f2);
	}else
		return -1;
	return 0;
}

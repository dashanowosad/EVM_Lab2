#include "basic.h"

int CheckComand(char *S, int index){
	int adr;
	if(strcmp(S, "REM") == 0);
	else if(strcmp(S, "INPUT") == 0) adr = INPUT_function(index);
	else if(strcmp(S, "PRINT") == 0) adr = PRINT_function(index);
	else if(strcmp(S, "GOTO") == 0);
	else if(strcmp(S, "IF") == 0);
	else if(strcmp(S, "LET") == 0);
	else if(strcmp(S, "END") == 0) adr = END_function(index);
	return adr;
}

int END_function(int index){
	if (index < 9) 
		fprintf(f2,"0%d HALT 00\n",index);
	else if (index > 9)
		fprintf(f2,"%d HALT 00\n",index);
	else
		return -1;
	return ++index;
}

int INPUT_function(int index){
	int new_adr = 99 - index;
	char wrong;
	fscanf(f1,"%c", &wrong);
	fscanf(f1, "%c", &A[new_adr]);
	if (index < 9) 
		fprintf(f2,"0%d READ %d\n",index, new_adr);
	else if (index > 9)
		fprintf(f2,"%d READ %d\n",index, new_adr);
	else 
		return -1;
	return ++index;
	
}
int PRINT_function(int index){
	char symbol, space;
	int j;
	fscanf(f1,"%c", &space);
	fscanf(f1,"%c", &symbol);
	for(j = 0; j < 100; j++){
		if (symbol == A[j]) break;	
	}
	if ((index < 9) && (j < 9))
		fprintf(f2,"0%d WRITE 0%d\n",index, j);
	else if ((index > 9) && (j < 9))
		fprintf(f2,"%d WRITE 0%d\n",index, j);
	else if ((index < 9) && (j > 9))
		fprintf(f2,"0%d WRITE %d\n",index, j);
	else if ((index > 9) && (j > 9))
		fprintf(f2,"%d WRITE %d\n",index, j);
	else 
		return -1;
	return ++index;
}
int main(){
	char adress[3], space, command[7];
	int i = 0;
	f1 = fopen("basic.txt", "r");
	f2 = fopen("as.txt", "w");

	while(!feof(f1)){
		fscanf(f1,"%s", &adress); // считали адрес
		fscanf(f1,"%s",&command);
		if(feof(f1)) break;
		i = CheckComand(command, i);
		printf("%s %d\n",adress,i);	
			
	}
	
	return 0;
}


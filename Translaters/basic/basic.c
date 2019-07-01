#include "basic.h"

int CheckComand(char *S, int index){
	int adr;
	if(strcmp(S, "REM") == 0);
	else if(strcmp(S, "INPUT") == 0) adr = INPUT_function(index);
	else if(strcmp(S, "PRINT") == 0) adr = PRINT_function(index);
	else if(strcmp(S, "GOTO") == 0) adr = GOTO_function(index);
	else if(strcmp(S, "IF") == 0) adr = IF_function(index);
	else if(strcmp(S, "LET") == 0);
	else if(strcmp(S, "END") == 0) adr = END_function(index);
	return adr;
}

int END_function(int index){
	if (index < 10) 
		fprintf(f2,"0%d HALT 00\n",index);
	else if (index > 10)
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
	if (index < 10) 
		fprintf(f2,"0%d READ %d\n",index, new_adr);
	else if (index > 10)
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
	if ((index < 10) && (j < 10))
		fprintf(f2,"0%d WRITE 0%d\n",index, j);
	else if ((index > 10) && (j < 10))
		fprintf(f2,"%d WRITE 0%d\n",index, j);
	else if ((index < 10) && (j > 10))
		fprintf(f2,"0%d WRITE %d\n",index, j);
	else if ((index > 10) && (j > 10))
		fprintf(f2,"%d WRITE %d\n",index, j);
	else 
		return -1;
	return ++index;
}

int GOTO_function(int index){
	char adress[2],space;
	int j, adr;	
	fscanf(f1,"%c", &space);
	fscanf(f1,"%s",adress);
	adr = atof(adress);
	//printf("%s",adress);
	for (j = 0; j < 1000; j++)
		if(Adress[j] == adr) break;
	if ((index < 10) && (j < 10))
		fprintf(f2,"0%d JUMP 0%d\n",index, j);
	else if ((index > 10) && (j < 10))
		fprintf(f2,"%d JUMP 0%d\n",index, j);
	else if ((index < 10) && (j > 10))
		fprintf(f2,"0%d JUMP %d\n",index, j);
	else if ((index > 10) && (j > 10))
		fprintf(f2,"%d JUMP %d\n",index, j);
	else 
		return -1;
	return ++index;
	
}
int IF_function(int index){
	char symbol, space, sign, number[5], command[4], adress[3], c;
	int j, num, adr;
	//printf("%c",symbol);
	fscanf(f1,"%c", &space);
	fscanf(f1,"%c", &symbol);//считали переменную
	fscanf(f1,"%c", &space);
	fscanf(f1,"%c", &sign);//считали знак
	fscanf(f1,"%c", &space);
	
	
	
	for (j = 0; j < 5; j++){
		fscanf(f1,"%c", &c);//считали цифру
		if (c != ' ') number[j] = c;
		else break;
	}
	//printf("%c\n",number);
	
	fscanf(f1,"%c", &space);
	fscanf(f1,"%s", &command); //считали GOTO
	fscanf(f1,"%c", &space); 
	fscanf(f1,"%s", &adress);//считали адрес
	//printf("%s",number);
	adr = atof(adress);
	for (j = 0; j < 1000; j++){//нашли адрес
		if(Adress[j] == adr) break;
		//else printf("%d",Adress[j]);	
	}	
	adr = j;
	if (adr == 1000){ //скачок вперед
		adr = atof(adress);
		adr/=10;	
	}
	for(j = 0; j < 100; j++){//нашли, где храним символ
		if (symbol == A[j]) break;	
	}
	if ((index < 10) && (j < 10))
		fprintf(f2,"0%d LOAD 0%d\n",index, j);
	else if ((index > 10) && (j < 10))
		fprintf(f2,"%d LOAD 0%d\n",index, j);
	else if ((index < 10) && (j > 10))
		fprintf(f2,"0%d LOAD %d\n",index, j);
	else if ((index > 10) && (j > 10))
		fprintf(f2,"%d LOAD %d\n",index, j);
	else 
		return -1;
	index++;

//////////////////////////////////////
	num = atof(number);
	//printf("%d",num);
	if (num != 0){
		adr++;
		for(j = 99; j >= 0; j--) //ищем свободную ячейку
			if (A[j] == '0') break;	
		Member[j] = num;
		//printf("%d %d", j, num);
		if ((index < 10) && (j < 10))
			fprintf(f2,"0%d SUB 0%d\n",index, j);
		else if ((index > 10) && (j < 10))
			fprintf(f2,"%d SUB 0%d\n",index, j);
		else if ((index < 10) && (j > 10))
			fprintf(f2,"0%d SUB %d\n",index, j);
		else if ((index > 10) && (j > 10))
			fprintf(f2,"%d SUB %d\n",index, j);
		else 
			return -1;
		index++;
	}
////////////////////////////////
	
	if (sign == '='){
		if ((index < 10) && (adr < 10))
			fprintf(f2,"0%d JZ 0%d\n",index, adr);
		else if ((index > 10) && (adr < 10))
			fprintf(f2,"%d JZ 0%d\n",index, adr);
		else if ((index < 10) && (adr > 10))
			fprintf(f2,"0%d JZ %d\n",index, adr);
		else if ((index > 10) && (adr > 10))
			fprintf(f2,"%d JZ %d\n",index, adr);
		else 
			return -1;
	}
	else if (sign == '>'){
		if ((index < 10) && (adr < 10))
			fprintf(f2,"0%d JUMP 0%d\n",index, adr);
		else if ((index > 10) && (adr < 10))
			fprintf(f2,"%d JUMP 0%d\n",index, adr);
		else if ((index < 10) && (adr > 10))
			fprintf(f2,"0%d JUMP %d\n",index, adr);
		else if ((index > 10) && (adr > 10))
			fprintf(f2,"%d JUMP %d\n",index, adr);
		else 
			return -1;
	}
	else if (sign == '<'){
		if ((index < 10) && (adr < 10))
			fprintf(f2,"0%d JNEG 0%d\n",index, adr);
		else if ((index > 10) && (adr < 10))
			fprintf(f2,"%d JNEG 0%d\n",index, adr);
		else if ((index < 10) && (adr > 10))
			fprintf(f2,"0%d JNEG %d\n",index, adr);
		else if ((index > 10) && (adr > 10))
			fprintf(f2,"%d JNEG %d\n",index, adr);
		else 
			return -1;
	}


	return ++index;
	
	
}
int main(){
	char adress[3], space, command[7], res[4];
	int i = 0, j;
	f1 = fopen("basic.txt", "r");
	f2 = fopen("as.txt", "w");
	for (j = 0; j < 100; j++){
		A[j] = '0';
		Member[j] = 0;
		//printf("%c ",A[j]);
	}
	
	
	while(!feof(f1)){
		fscanf(f1,"%s", &adress); // считали адрес с пробелом
		fscanf(f1,"%s", &command);
		if(feof(f1)) break;
		Adress[i] = atof(adress);
		//printf("%d\n",Adress[i]);
		i = CheckComand(command, i);
			
			
	}
	
	for (j = 0; j < 100; j++){
		if (Member[j] != 0){
			if (j < 10) 
				fprintf(f2,"0%d = ", j);
			else if (j > 10)
				fprintf(f2,"%d = ", j);
			else
				return -1;		
			
			sprintf(res, "%0x", Member[j]);
			if (Member[j] < 16)
				fprintf(f2,"+000%s ", res);
			else if ((Member[j] > 15) && (Member[j] < 256))
				fprintf(f2,"+00%s ", res);
			else if ((Member[j] > 255) && (Member[j] < 4096))
				fprintf(f2,"+0%s ", res);
			else if (Member[j] > 4095)
				fprintf(f2,"+%s ", res);
			else 
				return -1;
			//printf("%d", Member[j]);
		}
	}
	/*int m = 10;
	char c[10];
	sprintf(c, "%0x" ,m);
	printf("%s",c);*/
	return 0;
}


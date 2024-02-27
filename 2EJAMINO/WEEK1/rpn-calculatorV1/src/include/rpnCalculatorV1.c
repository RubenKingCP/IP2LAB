#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getOp(void);
void putInStack(void);
int getFromStack(void);
void add(void);
void mul(void);
void presentResult(void);

char input[20];
int inputType;

int main(int argc, char *argv[]) {
	printf("RPN Calculator started\n");
//	inputType=getOp();
	while((inputType=getOp())!=EOF){
		//printf("inputType= %c(as char)\t %d(as decimal)\n",inputType,inputType);
		switch(inputType){
			case NUMBER:
				putInStack();
				break;
			case '+':
				add();
				break;
			case '*':
				mul();
				break;
			case '=':
				presentResult();
				break;
			default:
				printf("operation not suported\n");
			
		}
//		inputType=getOp();
	}
	
	return 0;
}

int getOp(void){
	char ch;
	//printf("getOp\n");
	ch=getchar();
    while(ch==' '|| ch=='\n') ch=getchar();
	if(isdigit(ch))
		return NUMBER;
    else
		return ch;
}

void putInStack(void){
	printf("putInStack\n");
}

int getFromStack(void){
	
}

void add(void){
	printf("add\n");
}
void mul(void){
	printf("mul\n");
}
void presentResult(void){
	printf("Present result\n");
}
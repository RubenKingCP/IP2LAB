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

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
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
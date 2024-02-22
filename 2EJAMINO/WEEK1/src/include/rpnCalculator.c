#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 1
#define MAX_SIZE 40

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct stack
{
    int numbers[MAX_SIZE];
    int top;
}Stack;



int getOp(void);
void putInStack(int value);
int getFromStack(void);
void add(void);
void sub(void);
void mul(void);
void divide(void);
void presentResult(void);

char input[20];
int inputType;
int number;
Stack stack;

int main(int argc, char *argv[]) {
	printf("RPN Calculator\n");
    //INitialize stack
    stack.top = 0;
//	inputType=getOp();
	while((inputType=getOp())!=EOF){
		//printf("inputType= %c(as char)\t %d(as decimal)\n",inputType,inputType);
		switch(inputType){
			case NUMBER:
				putInStack(number);
				break;
			case '+':
				add();
				break;
            case '-':
                sub();
                break;
			case '*':
				mul();
				break;
            case '/':
                divide();
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
	ch=getchar();
	if(isdigit(ch)) {
        number = ch - 48;
		return NUMBER;
    }
	else return ch;
}

void putInStack(int value){
    if (stack.top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack.numbers[stack.top++] = value;
	printf("\n%d\n", value);
}

int getFromStack(void){
    if (stack.top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int num = stack.numbers[stack.top - 1];
    stack.numbers[stack.top--] = 0;
    return num;
}   

void add(void){
    int last = getFromStack();
    int secondLast = getFromStack();
    int result = last + secondLast;
    putInStack(result);
}
void sub(void){
    int last = getFromStack();
    int secondLast = getFromStack();
    int result = last - secondLast;
    putInStack(result);
}
void mul(void){
	int last = getFromStack();
    int secondLast = getFromStack();
    int result = last * secondLast;
    putInStack(result);
}
void divide(void){
    int last = getFromStack();
    int secondLast = getFromStack();
    if(secondLast == 0){
        printf("Divisor equals 0. Aborting...");
        return;
    }
    int result = last / secondLast;
    putInStack(result);
}
void presentResult(void){
    if(stack.top != 1){
        printf("\nToo many numbers. Do more operations!\n");
        return;
    }
    printf("\nResult: %d\n", stack.numbers[0]);
}
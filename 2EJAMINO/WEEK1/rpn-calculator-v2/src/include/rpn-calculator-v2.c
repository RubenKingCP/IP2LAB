#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mathTools.h"

#define NUMBER 1

typedef struct {
    int num;
    int type;
} Operator;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Operator getOp(void);
void putInStack(int num);
int getFromStack(int num);
void add(Stack * stack);
void mul(Stack * stack);
void presentResult(void);


char input[20];
Operator inputType;
Stack stack;


int main(int argc, char *argv[]) {
	printf("RPN Calculator started\n");
    stack.top = 0;
//	inputType=getOp();
	while((inputType = getOp()).type !=EOF){
		//printf("inputType= %c(as char)\t %d(as decimal)\n",inputType,inputType);
		switch(inputType.type){
			case NUMBER:
				putInStack(inputType.num);
				break;
			case '+':
				add(&stack);
				break;
			case '*':
				mul(&stack);
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

Operator getOp() {
    Operator input;
    int c;
    while ((c = getchar()) == ' ' || c == '\n'); // Skip whitespace characters
    if (isdigit(c)) {
        // Read the whole number
        input.num = c - '0'; // Convert character to integer
        while ((c = getchar()) != EOF && isdigit(c)) { // Gets charachters in row till we find a non-digit
            input.num = input.num * 10 + (c - '0'); // Shift previous digits left and add the new digit
        }
        input.type = NUMBER;
        return input;
    } else {
        input.num = c;
        input.type = c;
        return input;
    }
}


void putInStack(int num){
	printf("putInStack %d\n", num);
    push(num, &stack); // Push number to stack
}

int getFromStack(int num){
	
}


void add(Stack *stack) {
    int tempNum = pop(stack);
    tempNum += pop(stack); //Get popped element
    push(tempNum, stack);
    printf("Added\n");
}

void mul(Stack *stack) {
    int tempNum = pop(stack);
    tempNum *= pop(stack); //Get popped element
    push(tempNum, stack);
    printf("Multiplied\n");
}

void presentResult(){
    printf("Result = %d", stack.stack[0]);
}
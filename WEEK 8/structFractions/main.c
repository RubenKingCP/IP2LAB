#include <stdio.h>
#include <stdlib.h>
#include "headers/i2p.h"

//St prototypes
void add(int num1, int num2, int num3, int num4);

void sub(int num1, int num2, int num3, int num4);

void multi(int num1, int num2, int num3, int num4);

void divide(int num1, int num2, int num3, int num4);

void simplify(int upper, int base);

void performOperation(char operator, int num1, int num2, int num3, int num4);

int main() {
	//Variables
	int numOfNumbers, i;
	
	//Get number of times u want to run the program
	printf("How many times : ");
	scanf("%d" , &numOfNumbers);
	
	for (i = 0; i < numOfNumbers; i++) {
		//Get the expression parameters
		Expression fractions = readExpression();
		//Perform the operation
		performOperation(fractions.operator, fractions.op1.ar, fractions.op1.par, fractions.op2.ar, fractions.op2.par);
	}
	return 0;
}

void add(int num1, int num2, int num3, int num4) {
	//Set variables
	int upper, base;
	//Get the same base
	base = num2 * num4;
	//Multiply the upper numbers
	num1 = num1 * num4;
	num3 = num3 * num2;
	//Add them
	upper = num1 + num3;
	simplify(upper, base);
};

void sub(int num1, int num2, int num3, int num4) {
	//Set variables
	int upper, base;
	//Get the same base
	base = num2 * num4;
	//Multiply the upper numbers
	num1 = num1 * num4;
	num3 = num3 * num2;
	//Sub them
	upper = num1 - num3;
	//Simplify
	simplify(upper, base);
}

void multi(int num1, int num2, int num3, int num4) {
	//Set variables
	int base, upper;
	//Get same base
	base = num2 * num4;
	//Get upper number
	upper = num1 * num3;
	//Simplify
	simplify(upper, base);
}

void divide(int num1, int num2, int num3, int num4){
	//Set variables
	int base, upper;
	//Get same base
	base = num2 * num3;
	//Get upper number
	upper = num1 * num4;
	simplify(upper, base);
}

void simplify(int upper, int base) {
	//Set i variable
	int i, num = 0;
	//Loop for the base
	for (i = 1; i <= base; i++ ) {
		//Check to see if i divides both numbers
		if (upper % i == 0 && base % i == 0) {
			//Divide the numbers
			upper = upper / i;
			base = base / i;
			//Set i to 2 and repeat
			i = 1;
		}
	}
	
	//Check case and print the matching case
	if (upper == base) {
		printf("\t1\n");
	} 
	//Check if upper > base
	else if (upper > base) {
		do {
			//Remove from the upper the base and 1 to number
			num++;
			upper -= base;
		} while (upper >= base);
		//If there is no leftover
		if (upper == 0) {
			printf("\t%d\n", num);
		} else printf("\t%d %d/%d", num, upper, base);
	}
	else {
		//Print the numbers
		printf("\t%d/%d\n", upper, base);
	}
}

void performOperation(char operator, int num1, int num2, int num3, int num4) {
    switch(operator) {
        case '+':
            add(num1, num2, num3, num4);
            break;
        case '-':
            sub(num1, num2, num3, num4);
            break;
        case '*':
            multi(num1, num2, num3, num4);
            break;
        case '/':
            divide(num1, num2, num3, num4);
            break;
        default:
            break;
    }
}

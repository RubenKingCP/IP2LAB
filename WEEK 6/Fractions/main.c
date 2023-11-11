#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/i2p.h"

//St prototypes
void add(int num1, int num2, int num3, int num4);

void sub(int num1, int num2, int num3, int num4);

void multi(int num1, int num2, int num3, int num4);

void divide(int num1, int num2, int num3, int num4);

void simplify(char expression, int upper, int base);

int main() {
	//Variables
	char operatorExpr;
	int num1, num2, num3, num4;
	int numOfNumbers, i;
	
	//Get number of times u want to run the program
	printf("How many times : ");
	scanf("%d" , &numOfNumbers);
	
	for (i = 0; i < numOfNumbers; i++) {
		//Get the expression parameters
		readExpression(&operatorExpr, &num1, &num2, &num3, &num4);
		
		//Use the value to do the correct operation
		switch(operatorExpr){
				
			case '+':
				//Add numbers if +
				add(num1, num2, num3, num4);
				break;
			case '-':
				//Remove numbers if -
				sub(num1, num2, num3, num4);
				break;
			case '*':
				//Multiply number if *
				multi(num1, num2, num3, num4);
				break;
			case '/':
				//Divide number if /
				divide(num1, num2, num3, num4);
				break;
			default:
				break;
		}
	}
	return 0;
}

void add(int num1, int num2, int num3, int num4) {
	//Set variables
	int upper, base;
	//Give the expression charachter
	char expression = '+';
	//Get the same base
	base = num2 * num4;
	//Multiply the upper numbers
	num1 = num1 * num4;
	num3 = num3 * num2;
	//Add them
	upper = num1 + num3;
	simplify(expression, upper, base);
};

void sub(int num1, int num2, int num3, int num4) {
	//Set variables
	int upper, base;
	//Give the expression charachter
	char expression = '-';
	//Get the same base
	base = num2 * num4;
	//Multiply the upper numbers
	num1 = num1 * num4;
	num3 = num3 * num2;
	//Sub them
	upper = num1 - num3;
	//Simplify
	simplify(expression, upper, base);
}

void multi(int num1, int num2, int num3, int num4) {
	//Set variables
	int base, upper;
	//Give charachter charachter
	char expression = '*';
	//Get same base
	base = num2 * num4;
	//Get upper number
	upper = num1 * num3;
	//Simplify
	simplify(expression, upper, base);
}

void divide(int num1, int num2, int num3, int num4){
	//Set variables
	int base, upper;
	//Give the expression charachter
	char expression = '/';
	//Get same base
	base = num2 * num3;
	//Get upper number
	upper = num1 * num4;
	simplify(expression, upper, base);
}

void simplify(char expression, int upper, int base) {
	//Set i variable
	int i;
	//Loop for the base
	for (i = 1; i <= base; i++ ) {
		//Check to see if i divides both numbers
		if (upper % i == 0 && base % i == 0) {
			//Divide the numbers
			upper = upper / i;
			base = base / i;
			//Set i to 1 and repeat
			i = 1;
		}
	}
	//Print the numbers
	printf("%c %d/%d\n", expression, upper, base);
}

#include <stdio.h>
#include <stdlib.h>
#include "headers/i2p.h"

/*FUNCTION main
A.1 Declare variables: operatorExpr, num1, num2, num3, num4, numOfNumbers, i
A.2 Display the message "How many times: "
A.3 Get the number of iterations (numOfNumbers)
A.4 Loop for i < numOfNumbers with a step of 1
A.4.1 Call the function readExpression to get the expression parameters
A.4.2 Use the value of operatorExpr to perform the appropriate arithmetic operation
A.4.2.1 Call the functions add, sub, multi, or divide based on the operator
A.5 End the program

FUNCTION add
B.1 Declare variables: upper, base
B.2 Calculate the common denominator (base)
B.3 Calculate the products of the numerators (num1 * num4, num3 * num2)
B.4 Add the multiplied numerators
B.5 Call the simplify function with the parameters upper, base

FUNCTION sub
C.1 Declare variables: upper, base
C.2 Calculate the common denominator (base)
C.3 Calculate the products of the numerators (num1 * num4, num3 * num2)
C.4 Subtract the multiplied numerators
C.5 Call the simplify function with the parameters pper, base

FUNCTION multi
D.1 Declare variables: upper, base
D.2 Calculate the common denominator (base)
D.3 Calculate the product of the numerators (num1 * num3)
D.4 Call the simplify function with the parameters upper, base

FUNCTION divide
E.1 Declare variables: upper, base
E.2 Calculate the common denominator (base)
E.3 Calculate the product of the numerators (num1 * num4)
E.4 Call the simplify function with the upper, base

FUNCTION simplify
F.1 Declare variable: i
F.2 Loop for each i from 1 to base with a step of 1
F.2.1 Check if i divides both numerators
F.2.1.1 Divide the numerators by i
F.2.1.2 Set i to 2 and repeat the check
F.3 Display the simplified expression based on the case
*/

//St prototypes
void add(int num1, int num2, int num3, int num4);

void sub(int num1, int num2, int num3, int num4);

void multi(int num1, int num2, int num3, int num4);

void divide(int num1, int num2, int num3, int num4);

void simplify(int upper, int base);

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
	for (i = 2; i <= base; i++ ) {
		//Check to see if i divides both numbers
		if (upper % i == 0 && base % i == 0) {
			//Divide the numbers
			upper = upper / i;
			base = base / i;
			//Set i to 2 and repeat
			i = 2;
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

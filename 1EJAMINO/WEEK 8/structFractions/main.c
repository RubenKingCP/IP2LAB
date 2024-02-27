#include <stdio.h>
#include <stdlib.h>
#include "headers/i2p.h"

void performOperation(Expression fractions);

void add(Fraction op1, Fraction op2);

void sub(Fraction op1, Fraction op2);

void multi(Fraction op1, Fraction op2);

void divide(Fraction op1, Fraction op2);

void simplify(int upper, int base);

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
		performOperation(fractions);
	}
	return 0;
}

void performOperation(Expression fractions) {
    switch(fractions.operator) {
        case '+':
            add(fractions.op1, fractions.op2);
            break;
        case '-':
            sub(fractions.op1, fractions.op2);
            break;
        case '*':
            multi(fractions.op1, fractions.op2);
            break;
        case '/':
            divide(fractions.op1, fractions.op2);
            break;
        default:
            break;
    }
}

void add(Fraction op1, Fraction op2) {
	//Set variables
	int upper, base;
	int ar1, ar2;
	//Get the same base
	base = op1.par * op2.par;
	//Check to see if base is 0
	if (base == 0) {
		printf("Detected zero in par error!\n");
		return;
	}
	//Multiply the upper numbers
	ar1 = op1.ar * op2.par;
	ar2 = op2.ar * op1.par;
	//Add them
	upper = ar1 + ar2;
	simplify(upper, base);
};

void sub(Fraction op1, Fraction op2) {
	//Set variables
	int upper, base;
	int ar1, ar2;
	//Get the same base
	base = op1.par * op2.par;
	//Check to see if base is 0
	if (base == 0) {
		printf("Detected zero in par error!\n");
		return;
	}
	//Multiply the upper numbers
	ar1 = op1.ar * op2.par;
	ar2 = op2.ar * op1.par;
	//Sub them
	upper = ar1 - ar2;
	//Simplify
	simplify(upper, base);
}

void multi(Fraction op1, Fraction op2) {
	//Set variables
	int base, upper;
	//Get same base
	base = op1.par * op2.par;
	//Check to see if base is 0
	if (base == 0) {
		printf("Detected zero in par error!\n");
		return;
	}
	//Get upper number
	upper = op1.ar * op2.ar;
	//Simplify
	simplify(upper, base);
}

void divide(Fraction op1, Fraction op2){
	//Set variables
	int base, upper;
	//Get same base
	base = op1.par * op2.ar;
	//Check to see if base is 0
	if (base == 0) {
		printf("Detected zero in par error!\n");
		return;
	}
	//Get upper number
	upper = op1.ar * op2.par;
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
		} else printf("\t%d %d/%d\n", num, upper, base);
	}
	else {
		//Print the numbers
		printf("\t%d/%d\n", upper, base);
	}
}


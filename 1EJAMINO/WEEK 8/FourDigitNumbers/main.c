#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	//Set variables
	int digit1 = 1, digit2 = 0, digit3 = 0, digit4 = 0, number = 0, numberPowered;
	printf("The numbers are: \n");
	
	while(number < 9999) {
		//System to get the number
		//Last digit
		digit4++;
		//Check if fourth digit = 10
		if (digit4 == 10) {
			//Third digit
			digit3++;
			//Set fourth to 0
			digit4 = 0;
			//Check if third digit = 10
			if (digit3 == 10) {
				//Second digit
				digit2++;
				//Set thrid to 0
				digit3 = 0;
				//Check if seconddigit = 10
				if (digit2 == 10) {
					//First digit
					digit1++;
					//Set second to 0
					digit2 = 0;
				}
			}
		}
		
		//Assign the digits to the number
		number = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
		
		//Get the sum of the powered numbers
		numberPowered = pow(digit1, 4) + pow(digit2, 4) + pow(digit3, 4) + pow(digit4, 4);
	
		if (numberPowered == number) {
			printf("%d\n", number);
		}
	}
	return 0;
}

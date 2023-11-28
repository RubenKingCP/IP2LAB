#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/i2p.h"
#define LENGTH 15

/* run this program using the console pauser or add your own getch, system("pause") or input loop 
void sortInc4Int(int *base,int numOfElements, int strWidth);
void sortDec4Int(int *base,int numOfElements, int strWidth);
*/

int main() {
	//Set variables
	int i,random;
	int array[LENGTH];
	int strWidth = sizeof(array[0]);
	
	//Mechanism to add randomized numbers to the array
	srand(time(NULL));
	for (i = 0; i < LENGTH; i++) {
		random = (rand() % 100);
		array[i] = random;
	}
	
	//Print the list in normal form
	printf("\tBase array of 0-99 numbers: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	
	//Sort number using the library function
	sortInc4Int(array, LENGTH, strWidth);
	
	//Print them in ascending order
	printf("\n\tAscending order array: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	
	//Sort number using the library function
	sortDec4Int(array, LENGTH, strWidth);
	
	//Print them in descending order
	printf("\n\tDescending order array: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

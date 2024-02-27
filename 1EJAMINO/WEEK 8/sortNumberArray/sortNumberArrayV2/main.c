#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 15


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void incBubbleSort(int *arr, int size);

void decBubbleSort(int *arr, int size);

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
	
	printf("Normal Array: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	
	incBubbleSort(array, LENGTH);
	
	printf("\nAscending Array: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	
	decBubbleSort(array, LENGTH);
	
	printf("\nDescending Array: ");
	for (i = 0; i < LENGTH; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

void incBubbleSort(int *arr, int size) {
	//Set variables
	int i,j;
	
	//How many passes through the array (Worst case)
	for (i = 0; i < size - 1; i++) {
		//Check all numbers in array
		//I used size - i - 1 cuz everytime it sorts the max number goes to the end
		for (j = 0; j < size - i - 1; j++) {
			//Compares current and next index
			if (arr[j] > arr[j + 1]) {
				//Swap them
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
		}
	}
}

void decBubbleSort(int *arr, int size) {
	//Set variables
	int i,j;
	
	//How many passes through the array
	for (i = 0; i < size - 1; i++) {
		//Check all numbers in array
		//I used size - i - 1 cuz everytime it sorts the min number goes to the end
		for (j = 0; j < size - i - 1; j++) {
			//Compares current and next index
			if (arr[j] < arr[j + 1]) {
				//Swap them
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
void displayArray(int ar[],int numOfElements);
void displayArrayStatus(int ar[],int numOfElements);
void moveBubbleUp(int ar[], int numOfElements, int pass);
void bubbleSort(int ar[], int numOfElements);
bool isSorted(int ar[],int numOfElements);



int main() {
	int ar[] = {3, 0, 2, 7,  5,  6,  9, 1, 8, 4, 9, 8};
	int numOfElements;
	printf("Bubble sort\n");
	
	numOfElements = sizeof(ar)/sizeof(int);
	
	displayArray(ar,numOfElements);
	displayArrayStatus(ar,numOfElements);
	
	bubbleSort(ar, numOfElements);
	
	displayArray(ar,numOfElements);
	displayArrayStatus(ar,numOfElements);
	return 0;
}

void displayArrayStatus(int ar[],int numOfElements){
 	printf("Array status: %s\n",isSorted(ar,numOfElements)?"sorted":"not sorted");
}

bool isSorted(int ar[],int numOfElements){
	int i;
	for(i=0;i<numOfElements-1;i++){
		if(ar[i]>ar[i+1])
	 	return false;
	}
	return true;
}
void displayArray(int ar[],int numOfElements){
	int i;
	for(i=0;i<numOfElements;i++)
		printf("%d\t",ar[i]);
	printf("\n");
}

void bubbleSort(int ar[], int numOfElements) {
	int i,j;
	int temp;
	for(j = 0;j<numOfElements - 1;j++) {
		moveBubbleUp(ar,numOfElements, j);
		printf("\nEnd of array pass for %d elements\n", numOfElements - j);
		system("pause");
	}
}

void moveBubbleUp(int ar[], int numOfElements, int pass){
	int i;
	int temp;
	for(i=0;i<numOfElements - 1;i++) {
		if(ar[i] > ar[i+1]) {
			temp = ar[i];
			ar[i] = ar[i+1];
			ar[i+1] = temp;
			printf("Iteration no%d-> ",i+1);
			displayArray(ar,numOfElements - pass);
		}	
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayArray(int ar[],int numOfElements);
void displayArrayStatus(int ar[],int numOfElements);
void moveBubbleUp(int ar[], int numOfElements);
void bubbleSort(int ar[], int numOfElements);
bool isSorted(int ar[],int numOfElements);

int ar[] = {1, 0, 8, 3, 6, 4, 9, 2, 7, 5, 4};

int main(int argc, char *argv[]) {
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
	moveBubbleUp(ar, numOfElements);
	printf("\nEnd of array pass\n");
	system("pause");
}

void moveBubbleUp(int ar[], int numOfElements){
	int i;
	int temp;
	for(i=0;i<numOfElements - 1;i++) {
		if(ar[i] > ar[i+1]) {
			temp = ar[i];
			ar[i] = ar[i+1];
			ar[i+1] = temp;
			printf("Iteration no%d-> ",i+1);
			displayArray(ar,numOfElements);
		}	
	}
}


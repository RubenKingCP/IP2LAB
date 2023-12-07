#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
void displayArray(int ar[],int numOfElements);
void displayArrayStatus(int ar[],int numOfElements);
void bubbleSort(int ar[], int numOfElements);
bool isSorted(int ar[],int numOfElements);

int ar[] = {3,5,4,7,2,8,1,0,9,6};

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
	int i,j;
	int temp;
	for(j = 0;j<numOfElements - 1;j++) {
		for(i=0;i<numOfElements - 1 - j;i++) {
			if(ar[i] > ar[i+1]) {
				temp = ar[i];
				ar[i] = ar[i+1];
				ar[i+1] = temp;
				printf("Iteration no%d-> ",i+1);
				displayArray(ar,numOfElements - j);
			}
		if(isSorted(ar, numOfElements) == true) {
			printf("\n");
			system("pause");
			return;
			}	
		}
		printf("\nEnd of array pass for %d elements\n\n", numOfElements - j);
		system("pause");
		printf("\n");
	}
}

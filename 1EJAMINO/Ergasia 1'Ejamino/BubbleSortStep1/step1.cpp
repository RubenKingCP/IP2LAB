#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayArray(int ar[], int size);
void arrayStatus(int ar[], int size);
void bubbleSort(int data[], int size);
bool isSorted(int ar[], int size);
void moveBubble(int ar[], int size);

int ar[] = {1, 0, 8, 3, 6, 4, 9, 2, 7, 5, 4};		

int main() {

	int numOfElements =sizeof(ar)/sizeof(int);
	displayArray(ar,numOfElements);
	arrayStatus(ar,numOfElements); 
	system("pause");
	bubbleSort(ar, numOfElements);
	displayArray(ar,numOfElements); 
	arrayStatus(ar,numOfElements); 
	return 0;
}

void displayArray(int ar[], int numOfElements) {
	int i;
	for(i=0;i<numOfElements;i++) {
		printf("%d\t", ar[i]);
	}
}

bool isSorted(int ar[],int numOfElements){
	int i;
	for(i=0;i<numOfElements-1;i++){
		if(ar[i]>ar[i+1])
	 		return false;
	}
	return true;
}

void arrayStatus(int ar[],int numOfElements){
 	printf("Array status: %s\n",isSorted(ar,numOfElements)?"sorted":"not sorted");
}

void moveBubble(int ar[], int numOfElements){
	int i,temp;
	for(i=0;i<numOfElements-1;i++){
		if(ar[i]>ar[i+1]){
			temp = ar[i];
			ar[i] = ar[i+1];
			ar[i+1] = temp;
		}
	}
}

void bubbleSort(int ar[], int numOfElements){
	moveBubble(ar, numOfElements);
}

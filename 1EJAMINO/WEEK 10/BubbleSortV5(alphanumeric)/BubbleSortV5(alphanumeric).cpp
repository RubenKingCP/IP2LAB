#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
void displayArray(char ar[][10],int numOfElements);
void displayArrayStatus(char ar[][10],int numOfElements);
void moveBubbleUp(char ar[][10], int numOfElements);
void bubbleSort(char ar[][10], int numOfElements);
bool isSorted(char ar[][10],int numOfElements);



int main() {
	char ar[][10] = {"cde", "abc", "cef","abb", "aab", "klm","kab", "gbc", "gab", "aaa", "abc"};
	int numOfElements;
	printf("Bubble sort\n");
	numOfElements = sizeof(ar)/sizeof(ar[0]);
	
	displayArray(ar,numOfElements);
	displayArrayStatus(ar,numOfElements);
	bubbleSort(ar, numOfElements);
	displayArray(ar,numOfElements);
	displayArrayStatus(ar,numOfElements);
	return 0;
}

void displayArrayStatus(char ar[][10],int numOfElements){
 	printf("Array status: %s\n",isSorted(ar,numOfElements)?"sorted":"not sorted");
}

bool isSorted(char ar[][10],int numOfElements){
	int i;
	for(i=0;i<numOfElements-1;i++){
		if(strcmp(ar[i], ar[i+1]) > 0)
	 	return false;
	}
	return true;
}
void displayArray(char ar[][10],int numOfElements){
	int i;
	for(i=0;i<numOfElements;i++)
		printf("%s\t",ar[i]);
	printf("\n");
}

void bubbleSort(char ar[][10], int numOfElements) {	
	moveBubbleUp(ar, numOfElements);
	//printf("\nEnd of array pass for %d elements\n\n", numOfElements);
	//system("pause");
	//printf("\n");
	if(!isSorted(ar, numOfElements)) {
			bubbleSort(ar, numOfElements - 1);
		}
	return;
}

void moveBubbleUp(char ar[][10], int numOfElements) {
	int i;
	char temp[10];
	for(i=0;i<numOfElements - 1;i++) {
		if(strcmp(ar[i], ar[i+1]) > 0) {
			strcpy(temp, ar[i]);
			strcpy(ar[i], ar[i+1]);
			strcpy(ar[i+1], temp);
			//printf("Iteration no%d-> ",i+1);
			//displayArray(ar,numOfElements);
		}
	}
}

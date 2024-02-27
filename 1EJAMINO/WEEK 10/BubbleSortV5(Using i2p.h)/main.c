#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "i2p.h"
/* run this program using the console pauser or add your own getch,
system("pause") or input loop */
void displayArray(char ar[][10],int numOfElements);
void displayArrayStatus(char ar[][10],int numOfElements);
bool isSorted(char ar[][10],int numOfElements);



int main() {
	char ar[][10] = {"cde", "abc", "cef","abb", "aab", "klm","kab", "gbc", "gab", "aaa", "abc"};
	int numOfElements;
	printf("Bubble sort\n");
	numOfElements = sizeof(ar)/sizeof(ar[0]);
	
	displayArray(ar,numOfElements);
	displayArrayStatus(ar,numOfElements);
	sortInc4String(ar, numOfElements, 10);
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



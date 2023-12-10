#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayArray(int *ar[], int numOfElements);
void displayArrayStatus(int *ar[], int numOfElements);
void moveBubbleUp(int *ar[], int numOfElements);
void bubbleSort(int *ar[], int numOfElements);
bool isSorted(int *ar[], int numOfElements);

int main() {
    int arr[] = {1, 0, 4, 3, 5, 2};
    int numOfElements, i;
    printf("Bubble sort\n");
    numOfElements = sizeof(arr) / sizeof(int);
    int *ar[numOfElements];
    for (i = 0; i < numOfElements; i++) {
        ar[i] = &arr[i];
    }

    displayArray(ar, numOfElements);
    displayArrayStatus(ar, numOfElements);
    bubbleSort(ar, numOfElements);
    displayArray(ar, numOfElements);
    displayArrayStatus(ar, numOfElements);
    return 0;
}

void displayArrayStatus(int *ar[], int numOfElements) {
    printf("Array status: %s\n", isSorted(ar, numOfElements) ? "sorted" : "not sorted");
}

bool isSorted(int *ar[], int numOfElements) {
    int i;
    for (i = 0; i < numOfElements - 1; i++) {
        if (*ar[i] > *ar[i + 1]) {
            return false;
        }
    }
    return true;
}

void displayArray(int *ar[], int numOfElements) {
    int i;
    for (i = 0; i < numOfElements; i++)
        printf("%d\t", *ar[i]); 
    printf("\n");
}

void bubbleSort(int *ar[], int numOfElements) {
    moveBubbleUp(ar, numOfElements);
    //printf("\nEnd of array pass for %d elements\n\n", numOfElements);
    //system("pause");
    printf("\n");
    if (!isSorted(ar, numOfElements)) {
        bubbleSort(ar, numOfElements - 1);
    }
    return;
}

void moveBubbleUp(int *ar[], int numOfElements) {
    int i, *temp;
    for (i = 0; i < numOfElements - 1; i++) {
        if (*ar[i] > *ar[i + 1]) {  
            temp = ar[i];
            ar[i] = ar[i + 1];
            ar[i + 1] = temp;
            //printf("Iteration no %d -> ", i + 1);
            //displayArray(ar, numOfElements);
        }
    }
}


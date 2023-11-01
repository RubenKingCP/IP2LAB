#include <stdio.h>
#include <stdlib.h>

int main()
{   
    //Variable to store the total amount of numbers
    int size; 

    //Get total of numbers
    printf("Enter amount of numbers: ");
    scanf("%d", &size);

    //Dynamic allocate memory in array
    int *array = (int *)malloc(size * sizeof(int));

    //for loop to get numbers
    for (int i = 0; i < size; i++) {
        //Enter numbers to array
        printf("Enter number: ");
        scanf("%d", &array[i]);
    }


    //Set the basemark
    int min = array[0];
    int max = array[0];

    //For loop to itirate through the array
    for (int i = 0; i < size; i++) {
        //Check if number is larger than max
        if (array[i] > max) max = array[i];

        //Check if number is smaller than min
        else if (array[i] < min) min = array[i];
    }

    //Print min and max
    printf("Min: %d\nMax: %d", min, max);
    return 0;
}

#include <stdio.h>
#define N 8


//Find the maximum number in array function
float maximum(float x[], int size){
    //Set max variable
    float max = x[0];

    //for loop to iterate through the rest of the array
    for (int i = 1; i < size; i++)
    {
        //If to check if the current number is higher than the privious ones
        if (max < x[i]) max = x[i]; 
    }
    
    //output max value
    return max;
};

int main()
{
    //Declare variables
    float max;
    float degrees[N]; //Declare array
    printf("Give values: "); //Ask for the array values

    //For loop to add numbers to array
    for (int i = 0; i < N; i++) {

        //System to get the numbers in array
        printf("Give the %d-th value: ", i); //Ask the current value 
        scanf("%f", &degrees[i]);   //Get the current Value
    }

    max = maximum(degrees, N); //Call the maximum array to get the highest number

    printf("The maximum is %f\n", max); //Print the highest number of array
    return 0;
}

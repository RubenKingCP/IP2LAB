#include <stdio.h>
#include <stdlib.h>

void fib(int c) {
    //Set Variables
    int a, b, count, result;
    a = 0;
    b = 1;
    
    //print starter numbers
    printf("%d %d ", a, b);

    //For loop to count from 1 to the numOfNumbers
    for (count = 0; count < c - 2; count++) {
        result = a + b;
        a = b;
        b = result;

        //Print Result
        printf("%d ", result );
    }
}

int main()
{
    //Set Variables
    int numOfNumbers;

    //Ask for how many numbers you want
    printf("How many numbers dou you want to show? \n");
    scanf("%d", &numOfNumbers);

    //Print The series name
    printf("Fibonachi Series: \n");

    //Use secondary function to get the sequence
    fib(numOfNumbers);
    return 0;
}



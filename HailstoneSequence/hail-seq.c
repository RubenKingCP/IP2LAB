#include <stdio.h>
#include <stdlib.h>

void displaySequence(int num) {

    //While loop for num != 1
    while (num != 1)
    {   

        //If to check if number is even or odd
        if (num % 2 == 0) {

            //Divide number by two
            num = num / 2;

            //Print the number
            printf("%d \n", num);
        } 
        else {   

            //Multiply by 3 and add 1
            num = 3*num + 1;

            //Print the number
            printf("%d \n", num);
        }  
    }
}


int main()
{   
    int num;
    //Print the program name
    printf("HAILSTONE SEQUENCE V4");

    //Ask for number to do the hailstone sequence
    printf("Enter number: \n");

    //Get the number
    scanf("%d", &num);

    //Do the sequence for that number    
    displaySequence(num);

    return 0;
}

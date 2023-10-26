#include <stdio.h>

int main()
{
    //Set variables
    int numOfNumbers, temp;
    printf("How many numbers will you enter?: ");
    scanf("%d", &numOfNumbers);

    int ysa, peysa = 1; //Set possible most frequent number and its appearances
    int sa, pesa = 0;   //Set most frequent number and its appearances

    //Get first number
    printf("Enter first number: ");
    scanf("%d", &temp);

    //Set the first number as a possible candidate
    ysa = temp;


    //For loop to itirate through the rest of the array
    for (int count = 0; count < numOfNumbers - 1; count++) {

        printf("Enter next number: ");
        scanf("%d", &temp);
        

        //Adds to times for the current mfn
        if (ysa == temp)
        {
            //Increase peysa
            peysa++;

            //If payse > pesa
            if (peysa > pesa) {

                //Make the sa to ysa
                sa = ysa;

                //The pesa to peysa
                pesa = peysa;

            } 
        }

        //Make the new number the ysa
        else
        {
            ysa = temp;
        }
        
        
    }

    printf("SA: %d \nPESA: %d", sa, pesa);
    return 0;
}

#include <stdio.h>

int main()
{
    //Set variables
    int min, max; //Here the min and max are stored
    int cnum; //Variable to get the current number
    int numOfNumbers; //Variable to store the total amount of numbers
    
    //Get total of numbers
    printf("Enter amount of numbers: ");
    scanf("%d", &numOfNumbers);

    //Get first number to get basemark
    printf("Enter number: ");
    scanf("%d", &cnum);

    //Set basemarks
    max = cnum;
    min = cnum;

    //for loop to get rest numbers
    for (int i = 1; i < numOfNumbers; i++) {
        printf("Enter number: ");
        scanf("%d", &cnum);
        
        //if conditional to check if cnum larger than max
        if (cnum > max) max = cnum;
        
        //else if conditional to check if cnum smaller than min
        else if (cnum < min) min = cnum;
    }

    //Print the min and max numbers
    printf("Min: %d\nMax: %d", min, max);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


//Function to find prime numbers
int isPrime(int a) {
    for (int count = 2; count < a;count++) {
        if (a % count == 0) {
            return 0;
        }
    }
    return 1;
}


//Function to find divisors
void findDivisors(int a) {
    //Iterate through all 1 -> number
    for (int count = 1; count <= a; count++) {

        //If module is 0 printf the current number
        if (a % count == 0)
        {
            printf("%d\n", count);
        }
    }
}

int main()
{
    //Set varible num
    int num;

    //Ask and get number
    printf("Write a number:");
    scanf("%d", &num);

    //If conditional to check if number is prime or not
    if (isPrime(num)) {
        printf("The number is prime");
        return 0;
    }
    else 
        //Function to print divisors
        printf("The number's divisor's are: \n");
        findDivisors(num);
        return 0;
}

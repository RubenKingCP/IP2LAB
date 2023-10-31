#include <stdio.h>

//HOMEMADE CALCULATOR
enum operators {
    ADD,
    SUB,
    MUL,
    DIV,
    EXIT
};

//add two numbers
int add(int a, int b) {
    int result;
    result = a + b;
    return result;
}

//substract two numbers
int substract(int a, int b) {
    int result;
    result = a - b;
    return result;
}

//divide two numbers first / second
int divide(int a, int b) {
    int result;
    result = a / b;
    return result;
}

//multiply two numbers
int multiply(int a, int b) {
    int result;
    result = a * b;
    return result;
}

int main()
{
    //Set variables
    long long int a, b, tmp;
    int flick = 1;
    int operator;

    //Get first number
    printf("Enter first number: ");
    scanf("%lld", &a);

    //Get second number
    printf("Enter second number: ");
    scanf("%lld", &b);

    //While loop so it will keep asking the user
    while (flick != 0)
    {
        //Ask and get the user's choice
        printf("Choose +, -, *, /, EXIT (0, 1, 2, 3, 4): ");
        scanf("%d", &operator);

        //Switch to check the operator and do the corresponding operation
        switch (operator)
        {
        case ADD:
            tmp = add(a, b);
            printf("The addition is equal to %lld\n", tmp);
            break;
        case SUB:
            tmp = substract(a, b);
            printf("The substraction is equal to %lld\n", tmp);
            break;
        case DIV:
            //In case of a xero division
            if (b == 0)
            {
                printf("Can't divide\n");
                break;
            }
            tmp = divide(a, b);
            printf("The division is equal to %lld\n", tmp);
            break;
        case MUL:
            tmp = multiply(a, b);
            printf("The multiplication is equal to %lld\n", tmp);
            break;
        case EXIT:
            printf("\nEnding program...\n");
            flick = 0;
            break;

        // Default message if user types anything else
        default:
            printf("Error try again!\n");
            break;
        }
    }
    return 0;
}

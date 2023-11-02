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
void add(int a, int b) {
    int result;
    result = a + b;
    printf("The addition is equal to %d\n", result);
}

//substract two numbers
void substract(int a, int b) {
    int result;
    result = a - b;
    printf("The substraction is equal to %d\n", result);
}

//divide two numbers first / second
void divide(int a, int b) {
    //In case of a xero division
    if (b == 0) printf("Can't divide\n");
    else {
        int result;
        result = a / b;
        printf("The division is equal to %d\n", result);
    }
}

//multiply two numbers
void multiply(int a, int b) {
    int result;
    result = a * b;
    printf("The multiplication is equal to %d\n", result);
}

int main()
{
    //Set variables
    int a, b, tmp;
    int flick = 1;
    int operator;

    //Get first number
    printf("Enter first number: ");
    scanf("%d", &a);

    //Get second number
    printf("Enter second number: ");
    scanf("%d", &b);

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
            add(a, b);
            break;
        case SUB:
            substract(a, b);
            break;
        case DIV:
            divide(a, b);
            break;
        case MUL:
            multiply(a, b);
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
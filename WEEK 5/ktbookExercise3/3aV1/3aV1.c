#include <stdio.h>

//HOMEMADE CALCULATOR
enum operators {
    ADDITION,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXIT
};

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

    
    while (flick != 0)
    {
        printf("Choose +, -, *, /, EXIT (0, 1, 2, 3, 4): ");
        scanf("%d", &operator);
        printf("%d", operator);
        switch (operator)
        {
        case ADDITION:
            tmp = a + b;
            printf("\nThe addition is equal to %d\n", tmp);
            break;
        case SUBSTRACTION:
            tmp = a - b;
            printf("\nThe substraction is equal to %d\n", tmp);
            break;
        case DIVISION:
            if (b == 0)
            {
                printf("\nCan't divide\n");
                break;
            }
            tmp = a / b;
            printf("\nThe division is equal to %d\n", tmp);
            break;
        case MULTIPLICATION:
            tmp = a * b;
            printf("\nThe multiplication is equal to %d\n", tmp);
            break;
        case EXIT:
            printf("\nEnding program...\n");
            flick = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int i, num1, num2, result;

int main()
{   
    num1 = 0;
    num2 = 1;
    printf("%d \n", num1);
    printf("%d \n", num2);
    for (i = 0; i < 10; i++)
    {
        result = num1 + num2;
        num1 = num2;
        num2 = result;
        printf("%d \n", result );
    }
    
    system("pause");
    return 0;
}
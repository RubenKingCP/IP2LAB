#include <stdio.h>
#include <stdlib.h>

int isPrime(int a) {
    int count;
    for (count = 2; count < a;count++) {
        if (a % count == 0) {
            return 0;
        }
    }
    return 1;
}

void findDivisors(int a) {
    int count;
    for (count = 1; count <= a; count++) {
        if (a % count == 0)
        {
            printf("%4d", count);
        }
        
    }
}

int main()
{
    int num;
    printf("Write a number:");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("The number's divisors are only itself: %d and 1", num);
        return 0;
    }
    else 
        findDivisors(num);
    return 0;
}

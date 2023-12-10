#include <stdio.h>
#include <math.h>

int main() {
    printf("The numbers are: \n");

    for (int num = 1000; num <= 9999; ++num) {
        int digit1 = num / 1000;
        int digit2 = (num / 100) % 10;
        int digit3 = (num / 10) % 10;
        int digit4 = num % 10;

        int numberPowered = pow(digit1, 4) + pow(digit2, 4) + pow(digit3, 4) + pow(digit4, 4);

        if (numberPowered == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}

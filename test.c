#include <stdio.h>
#include <string.h>
#include <math.h>
int power(int a, int b) {
    int power = a;
    for (int i = 1; i < b; i++) {
        power *= a;
    }
    return power;
}

int main()
{   
    int number = 2391, len;
    char string[21];
    sprintf(string, "%d", number);
    len = strlen(string);
    int array[len];
    
    for (int i = 1; i <= len; i++) {
        array[i] = (number / power(10, len - i)) * power(10, len - i);
        printf("%d\n", array[i]);
        number = number - array[i];

    }

    return 0;
}





/*int starNum, modifiedNum, tmp, len;
    starNum = 401238;
    modifiedNum = (starNum / 10) * 10;
    tmp = starNum - modifiedNum;
    sprintf(string, "%d", starNum);
    len = strlen(string); 
    printf("Test: %d\nTest2: %d", starNum, len);*/
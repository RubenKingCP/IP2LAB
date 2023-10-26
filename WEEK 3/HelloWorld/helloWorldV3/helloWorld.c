#include <stdio.h>

void printVertical(char *word) {
    //For loop
    for (int count = 0; word[count] != '\0'; count++)
    {   
        //Print letter and make new line
        printf("%c \n", word[count]);
    }
}

int main()
{   
    //Set Variables
    char helloWorld[] = "Hello, World!";

    //Call name of program
    printf("VERTICAL HELLO WORLD PROGRAM \n");
    
    //Call function printVertical
    printVertical(helloWorld);
    
    return 0;
}

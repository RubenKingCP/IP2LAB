#include <stdio.h>
#include <string.h>
#define N 10

int count(char str[], char x) {
    //Set variables
    int num = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++) {
        if (str[i] == x)
        {
            num++;
        } 
    }
    
    return num;
}

int main()
{
    //Set variables
    char name[N];
    char ch;
    int appear;


    //Get the string system
    printf("Give name: "); //Ask the string 
    scanf("%s", name); //Get the string

    
    /*//Clear buffer
    fflush(stdin);  this line was said in the lesson but dunno(research)*/


    printf("Give charachter: "); //Ask charachter
    scanf(" %s", &ch); //Get charachter NOTE: i put an empty space in front of the %s cuz it skips any leading whitespace till it finds a non empty charachter

    //Get the count output and set it on variable appear
    appear = count(name, ch);

    //printf the apperances
    printf("The number of appearances of %c is: %d\n", ch, appear);

    return 0;
}

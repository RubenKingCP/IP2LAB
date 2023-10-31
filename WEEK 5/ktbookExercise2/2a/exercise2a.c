#include <stdio.h>
#include <string.h>
#define N 10



int main()
{
    
    //Set variables
    char name[N] = "NIKOY";
    int size = strlen(name);

    //Question a
    printf("Question A: ");
    printf("%s\n", name[2]);   //Print statement to print the name

    //Question b
    printf("\nQuestion B: ");
    for (int i = 0; i <=  size; i++) printf("%c ", name[i]);    //For loop to print letter by letter EDIT: Added a space in the print to make the result cleaner  

    //Question c
    printf("\n\nQuestion C: \n");
    for (int i = 0; i <  size; i++) printf("%c\n", name[i]);   //Normal for loop to print letter by letter and new line 

    //Question d
    printf("\nQuestion D: \n");
    for (int i = 0; i <  size; i++) printf("%s\n", &name[i]);  //With the &string[i] you will print from the specified position and after      
    
    //Question e
    printf("\nQuestion E: \n");
    for (int i = size; i > 0; i--) printf("%.*s\n",i, name);   //Using * u can set a variable for that number and with a negative counting for loop we get the desired result


    //First version of question E but got inspired by question d for new solution
    /*for (int i = size - 1; i >= 0; i--) {
        for (int y = 0; y <=  i; y++) printf("%c", name[y]);    
        printf("\n");    
    }*/
    return 0;
}

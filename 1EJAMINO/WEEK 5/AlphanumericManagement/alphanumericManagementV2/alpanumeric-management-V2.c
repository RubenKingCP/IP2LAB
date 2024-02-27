#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

//Enumaration
enum methods {
    	NORMAL,
    	LETTERS,
    	LINES,
    	REMOVESTART,
    	REMOVEEND,
    	REVERSEREMOVE,
    	EXIT
	};

//Prototypes
void normal(char * name);

void letterByLetter(char * name, int size);

void lineByLine(char * name, int size);

void removeLettersStart(char * name, int size);

void removeLettersEnd(char * name, int size);

void reverseRemoveLettersEnd(char * name, int size);


int main()
{
    //Set variables
    char name[N];
    enum methods method;

    //Ask name
    printf("Enter your surname: ");
    fgets(name, sizeof(name), stdin);

    int size = strlen(name);
   	
   	while (method != 6) {
	   	printf("Chooce method:\nNormal: 0\nLetter by letter: 1\nLine by line: 2\nRemove first letter each time: 3\nRemove last letter each time: 4\nReverse remove first letter: 5\nEXIT: 6\n");
	   	scanf("%d", &method);
	   	
	   	switch(method){
	   		case NORMAL:
	 			normal(name);
	    		break;
	    	case LETTERS:
	   			letterByLetter(name, size);
	   			break;
	   		case LINES:
	   			lineByLine(name, size);
    			break;
	    	case REMOVESTART:
	    		removeLettersStart(name, size);
	   			break;
	    	case REMOVEEND:
	   			removeLettersEnd(name, size);
	   			break;
	    	case REVERSEREMOVE:
	   			reverseRemoveLettersEnd(name, size);
	   			break;
	   		case EXIT:
	   			printf("Shutting down...");
	   			sleep(1);
    			break;
    		default:
    			printf("Error!");
    			break;
		    }		
   	 	}
    return 0;
}

void normal(char * name) {
	printf("%s\n", name);   //Print statement to print the name
}

void letterByLetter(char * name, int size) {
	int i;
	for (i = 0; i <=  size; i++) printf("%c ", name[i]);    //For loop to print letter by letter EDIT: Added a space in the print to make the result cleaner
	printf("\n");
}

void lineByLine(char * name, int size) {
	int i;
	for (i = 0; i <  size; i++) printf("%c\n", name[i]);   //Normal for loop to print letter by letter and new line 
}

void removeLettersStart(char * name, int size) {
	int i;
	for (i = 0; i <  size; i++) printf("%s\n", &name[i]);  //With the &string[i] you will print from the specified position and after
}

void removeLettersEnd(char * name, int size) {
	int i;
	for (i = size; i > 0; i--) printf("%.*s\n",i, name);   //Using * u can set a variable for that number and with a negative counting for loop we get the desired result

}

void reverseRemoveLettersEnd(char * name, int size) {
	char reversed[N];
	int i;
	//Reverse string
	while (name[i] != '\0') {
		reversed[i] = name[size - 1 - i];
		i++;
	}
	
	//Do the change using the reversed string
	removeLettersEnd(reversed, size);
}



//If word over 10 letters it has a problem

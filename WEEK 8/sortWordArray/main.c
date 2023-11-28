#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Set prototypes
void allocateMemory(int *size, char *** words);

void getWords(int size, char ** words);

void printWords(int size, char ** words);

void sortInc4String(char ** words, int size);

void sortDec4String(char ** words, int size);

void getWordsStats(int size, char ** words);

void getCharacterStats(int size, char ** words);

void freeMemory(int size, char ** words);

//Set enumaration
enum menu {
	TERMINATE,
	GET_WORDS,
	SHOW_WORDS,
	SORT_ASC,
	SORT_DESC,
	WORD_STATS,
	CHARACTER_STATS
};

int main() {
	//Set variables
	int word, size;
	char ** words;
	int choice = -1;
	
	//Get the first word
	allocateMemory(&size, &words);
	getWords(size, words);
	
	system("cls");
	
	while(choice != TERMINATE) {
		//Ask for choice
		printf("Choose action: \nTERMINATE: 0\nENTER WORDS: 1\nPRINT WORDS: 2\nSORT WORDS IN ASCENDING ORDER: 3\nSORT WORDS IN DESCENDING ORDER: 4\nGET WORDS STATS: 5\nGET CHARACTER STATS: 6\n");
		scanf("%d", &choice);
		
		//Clear console screeen
		system("cls");
		
		switch(choice) {
			case TERMINATE:
				freeMemory(size, words);
				printf("Exiting program...!");
				return 0;
				break;
			case GET_WORDS:
				//Free previous allocated memory
				freeMemory(size, words);
				//Get size and give memory
				allocateMemory(&size, &words);
				//Get words function
				getWords(size, words);
				//System to clear screen
				break;
			case SHOW_WORDS:
				//Print the word list
				printWords(size, words);
				//System to clear scree
				break;
			case SORT_ASC:
				//Sort words
				sortInc4String(words, size);
				//Print them sorted
				printWords(size, words);
				break;
			case SORT_DESC:
				//Sort words
				sortDec4String(words, size);
				//Print them sorted
				printWords(size, words);
				break;
			case WORD_STATS:
				//Get the words status
				getWordsStats(size, words);
				//System to clear screen
				break;
			case CHARACTER_STATS:
				//Get character status
				getCharacterStats(size, words);
				break;
			default:
				break;
		}	
		system("pause");
		system("cls");
	}
	
	return 0;
}

void allocateMemory(int *size, char *** words) {
	//Set variables
	int i;
	
	//Repeat till under 30 words
	do {
		//Ask number of words
		printf("Enter how many words you want(up to 30): ");
		scanf("%d", size);
	}
	while(*size > 30 || *size == 0);
	 
	//Check to see the size
	if (*size > 30) {
		printf("Word limit error!\nExiting program.");
		exit(0);
	}
	
	//Allocate the memory u need to the arrays
	*words = (char **)malloc(*size * sizeof(char*)); 
	for (i = 0; i < *size; i++) {
		(*words)[i] = (char*)malloc(30 * sizeof(char)); //Using 30 for word length 
	}
}

void getWords(int size, char ** words) {
	//Set variables
	int word;
	
	for (word = 0; word < size; word++) {
		//Ask word
		printf("\nEnter word: ");
		//Get word and start storing it from the end of the previous word
		scanf("%s", words[word]);
	}
}

void printWords(int size, char ** words) {
	//Set variables
	int word;
	//Print the words
	for (word = 0; word < size; word++) {
		printf("%s ", words[word]);
	}
	//Start new line
	printf("\n");
}

void sortInc4String(char ** words, int size) {
	//Set variables(assuming max length is 30)
	int i,j;
	char temp[30];
	
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if(strcmp(words[j], words[j + 1]) > 0) {
				//Swap words
				strcpy(temp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], temp);
			}
		}
	}
}

void sortDec4String(char ** words, int size) {
	//Set variables(assuming max length is 30)
	int i,j;
	char temp[30];
	
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if(strcmp(words[j], words[j + 1]) < 0) {
				//Swap words
				strcpy(temp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], temp);
			}
		}
	}
}

void getWordsStats(int size, char ** words) {
	//Set variables;
	int word, min, max, wordLen;
	float average;
	
	//Set starting values
	max = strlen(words[0]);
	min = strlen(words[0]);
	average = strlen(words[0]);
	
	//Itirate through each words to get size
	for (word = 1; word < size; word++) {
		//Get the word's length
		wordLen = strlen(words[word]);
		//Compare to current max and min
		if (wordLen > max) max = wordLen;
		if (wordLen < min) min = wordLen;
		//Add to average
		average += wordLen;
		}
	//Divide by size
	average = average / size;
	//Print status
	printf("Max Word Length - %d\nMin Word Length- %d\nAverage Word Length - %.2f\n", max, min, average);
}

void getCharacterStats(int size, char ** words) {
	//Set variables
	int word, letter, charCount, charMax, charMin, charTotal, maxWord, minWord;
	float charAverage;
	char character;
	
	//Charachter check
	printf("Enter charachter: ");
	scanf(" %c", &character);
	
	//Set starting values
	charMax = 0;
	charMin = 900; //30 words * 30 charachters maximum appearances
	charAverage = 0;
	charTotal = 0;
	
	//Itirate through words
	for (word = 0; word < size; word++) {	
		//Itirate through letters
		charCount  = 0;
		for (letter = 0; letter < strlen(words[word]);letter++) {
			if (words[word][letter] == character) {
				charCount++;
			}
		}
		//Add the current character count to the total
		charTotal += charCount;
		//Check if currentCount is bigger than max
		if (charMax < charCount) {
			charMax = charCount;
			//Store the current max charachter word position
			maxWord = word;
		}
		if (charMin > charCount) {
			charMin = charCount;
			//Store the current min charachter word position
			minWord = word;
		}
	}
	//Get average
	charAverage = (float)charTotal / (float)size;
	//Print Stats
	printf("TotalChar - %d\nAverageChar - %.2f\nMaxChar - %d\nMinChar - %d\nMaxWord - %s\nMinWord - %s\n", charTotal, charAverage, charMax, charMin, words[maxWord], words[minWord]);
}

void freeMemory(int size, char ** words) {
	int word;
	
	//Free the allocated memory once program is done
	for (word = 0; word < size; word++) {
		free(words[word]);
	}
	free(words);
}

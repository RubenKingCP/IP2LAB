#include <stdlib.h>
#include <stdio.h>
#include "headers/i2p.h"

#define SIZE 30
#define WIDTH 30

char words[SIZE][WIDTH];
int size;

void printWords();

void getWords();

void getCharacterStats();

void getWordStats();

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
	int choice = -1;
	
	//Get the first word
	getWords();
	
	system("cls");
	
	while(choice != TERMINATE) {
		//Ask for choice
		printf("Choose action: \nTERMINATE: 0\nENTER WORDS: 1\nPRINT WORDS: 2\nSORT WORDS IN ASCENDING ORDER: 3\nSORT WORDS IN DESCENDING ORDER: 4\nGET WORDS STATS: 5\nGET CHARACTER STATS: 6\n");
		scanf("%d", &choice);
		
		//Clear console screeen
		system("cls");
		
		switch(choice) {
			case TERMINATE:
				printf("Exiting program...!");
				return 0;
				break;
			case GET_WORDS:
				getWords();
				break;
			case SHOW_WORDS:
				//Print the word list
				printWords();
				break;
			case SORT_ASC:
				//Sort words
				sortInc4String(words, size, WIDTH);
				//Print them sorted
				printWords();
				break;
			case SORT_DESC:
				//Sort words
				sortDec4String(words, size, WIDTH);
				//Print them sorted
				printWords();
				break;
			case WORD_STATS:
				//Get the words status
				getWordsStats();
				break;
			case CHARACTER_STATS:
				//Get character status
				getCharacterStats();
				break;
			default:
				break;
		}	
		printf("\n");
		system("pause");
		system("cls");
	}
	
	return 0;
}
void getWords() {
	int i;
	
	printf("How many words: ");
	scanf("%d", &size);
	
	for (i = 0; i < size; i++) {
		printf("Enter word: ");
		scanf("%s", &words[i]);
	}
}

void printWords() {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s ", words[i]);
	}
}

void getWordsStats() {
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

void getCharacterStats() {
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

#include <stdio.h>

/*
function Main
A.1 Get the number of small and big bottles
A.2 Get the sum of the bottles and the money
A.3 Check with an if conditional if it satisfies the conditions and act accordingly
A.4.1 If it's bigger than 600 give 20% discount
A.4.2 If it's bigger than 200 or 3000 bottles give 8% discount
A.5 Print the total cost
A.6 Terminate program
*/


int main() {
	//Set variables
	int smallBottles, bigBottles, totalBottles;
	float totalCost;
	
	//Check for negative
	do {
		//Ask for the small bottles
		printf("How many small bottles do u want to buy: ");
		scanf("%d", &smallBottles);
	} while (smallBottles < 0);
	
	//Check for negative
	do {
		//Ask for big bottles
		printf("How many big bottles do u want to buy: ");
		scanf("%d", &bigBottles);
	} while(bigBottles < 0);
	
	
	//Get totalCost and totalBottles
	totalCost = 0.008 * smallBottles + 0.02 * bigBottles;
	totalBottles = smallBottles + bigBottles;
	
	if (totalCost > 600) {
		totalCost -= (totalCost * 20) / 100;
	} else if (totalCost > 200 || totalBottles > 3000) {
		totalCost -= (totalCost * 8) / 100;
	} 
	
	printf("You bought a total of %d bottles (%d small bottles and %d big bottles) for a price of %.2f$", totalBottles, smallBottles, bigBottles, totalCost);
	return 0;
}

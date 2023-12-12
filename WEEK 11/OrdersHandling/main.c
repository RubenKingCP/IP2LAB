#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum action {
	EXIT,
	GET_ORDER,
	SHOW_ORDER
};

typedef struct orderCost{
	float firstCost;
	float finalCost;
	int discount;
} Cost;

typedef struct orderDetails{
	char firstName[50];
	char lastName[50];
	char startDate[20];
	char deadLine[20];
	char endDate[20];
	Cost orderCost;
	int smallBottles;
	int bigBottles;
} Details;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Details getOrder();
Cost getOrderCost(int bigBottles, int smallBottles);
void showOrder(Details orderDetails);
void getCurrentDate();

int main() {
	//Set variable
	int action = -1;
	
	
	while(action != 0) {
		//Set the order variable
		Details currentOrder;
		
		//Get action
		printf("Enter action: ");
		scanf("%d", &action);
		
		//Set logic gate
		switch(action){
			case EXIT:
				return 0;
				break;
			case GET_ORDER:
				currentOrder = getOrder();
				break;
			case SHOW_ORDER:
				showOrder(currentOrder);
				break;
			default:
				break;
		}
	}
	return 0;
}

Details getOrder() {
	//Struct variable
	Details currentOrder;
	//Other variables
	char startDate[20];
	
	//Get the first part of details
	printf("Enter Small Bottles: ");
	scanf("%d", &currentOrder.smallBottles);
	printf("Enter Big Bottles: ");
	scanf("%d", &currentOrder.bigBottles);
	printf("Enter First Name of client: ");
	scanf("%s", &currentOrder.firstName);
	printf("Enter Last Name of client: ");
	scanf("%s", &currentOrder.lastName);
	printf("Enter Deadline(DD/MM/YY): ");
	scanf("%s", &currentOrder.deadLine);
	
	//Get the rest of details
	//Cost related info
	currentOrder.orderCost = getOrderCost(currentOrder.bigBottles, currentOrder.smallBottles);
	//Time info
	getCurrentDate(startDate);
	strcpy(currentOrder.startDate, startDate);
	//Order Status set to pending
	strcpy(currentOrder.endDate, "Pending");
	
	return currentOrder;
}

void showOrder(Details currentOrder){
	//Print the details
	printf("Order Details:\n");
	printf("\t-Small Bottles: %d\n", currentOrder.smallBottles);
	printf("\t-Big Bottles: %d\n", currentOrder.bigBottles);
	printf("\t-First Name: %s\n", currentOrder.firstName);
	printf("\t-Last Name: %s\n", currentOrder.lastName);
	printf("\t-Date Received: %s\n", currentOrder.startDate);
	printf("\t-Deadline: %s\n", currentOrder.deadLine);
	printf("\t-Starting Cost: %0.2f\n", currentOrder.orderCost.firstCost);
	printf("\t-Discount: %d\n", currentOrder.orderCost.discount);
	printf("\t-Final Cost: %0.2f\n", currentOrder.orderCost.finalCost);
	printf("\t-Date Delivered: %s\n", currentOrder.endDate);
}

Cost getOrderCost(int bigBottles, int smallBottles) {
	//Set cost variable
	Cost orderCost;
	//Set other variables
	int totalBottles;
	
	//Set values we need 
	totalBottles = bigBottles + smallBottles;
	orderCost.firstCost = bigBottles * 0.02 + smallBottles * 0.008;
	
	//Check conditions to set discount and final cost
	if(orderCost.firstCost > 600) {
		orderCost.discount = 20;
		orderCost.finalCost = 0.8 * orderCost.firstCost;
	} 
	else if(orderCost.firstCost > 200 || totalBottles > 3000) {
		orderCost.discount = 8;
		orderCost.finalCost = 0.92 * orderCost.firstCost;
	}
	else{
		orderCost.discount = 0;
		orderCost.finalCost = orderCost.firstCost;	
	}
	
	return orderCost;
}

void getCurrentDate(char startDate[20]) {
	//Set time variables
	time_t t;
	struct tm *tm_info;
	
	time(&t);//Get the time
	tm_info = localtime(&t); //Convert to format
	
	//Get time in DD/MM/YY format
	strftime(startDate, 20, "%d/%m/%y", tm_info);
}

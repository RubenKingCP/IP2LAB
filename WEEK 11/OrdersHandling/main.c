#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum action {
    EXIT,
    GET_ORDER,
    SHOW_ORDER,
    SHOW_ALL_ORDERS,
    SAVE_PENDING,
    LOAD_PENDING,
    FINISH_PENDING
};

typedef struct orderCost {
    float firstCost;
    float finalCost;
    int discount;
} Cost;

typedef struct orderDetails {
    char firstName[50];
    char lastName[50];
    char startDate[20];
    char deadLine[20];
    char endDate[20];
    Cost orderCost;
    int smallBottles;
    int bigBottles;
    int orderNumber;
    int orderStatus;
} Details;


Details getOrder(int numOrders);
Cost getOrderCost(int bigBottles, int smallBottles);
void showOrder(Details currentOrder);
void getCurrentDate();

int main() {
    // Set variables
    int action = -1;
    int numOrders = 0;
    Details orderArray[100]; // Assuming a maximum of 100 orders

    while (action != 0) {
        // Get action
        
        printf("Exit: 0\n");
		printf("Get order: 1\n");
		printf("Show current order: 2\n");
		printf("Show Orders: 3\n");
		printf("Save pending orders: 4\n");
		printf("Load pending order: 5\n");
		printf("Ready order: 6\n");
        printf("Enter action:\n");
        scanf("%d", &action);

        // Set logic gate
        switch (action) {
            case EXIT:
                return 0;
            case GET_ORDER:
                if (numOrders < 100) {
                    orderArray[numOrders++] = getOrder(numOrders);
                } else {
                    printf("Maximum number of orders reached.\n");
                }
                break;
            case SHOW_ORDER:
                showOrder(orderArray[numOrders - 1]);
                break;
            case SHOW_ALL_ORDERS:
                //showAllOrders(orderArray, numOrders);
                break;
            case SAVE_PENDING:
                //savePendingOrders(orderArray, numOrders);
                break;
            case LOAD_PENDING:
                //loadPendingOrders(orderArray, &numOrders);
                break;
            case FINISH_PENDING:
                //finishPendingOrder(orderArray, numOrders);
                break;
            default:
                printf("Invalid action.\n");
                break;
    	}
    }
    return 0;
}

Details getOrder(int numOrders) {
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
	currentOrder.orderNumber = numOrders;
	//Cost related info
	currentOrder.orderCost = getOrderCost(currentOrder.bigBottles, currentOrder.smallBottles);
	//Time info
	getCurrentDate(startDate);
	strcpy(currentOrder.startDate, startDate);
	//Order Status set to pending
	strcpy(currentOrder.endDate, "Pending");
	currentOrder.orderStatus = 0;
	
	return currentOrder;
}

void showOrder(Details currentOrder){
	//Print the details
	printf("Order No.%d Details:\n", currentOrder.orderNumber);
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

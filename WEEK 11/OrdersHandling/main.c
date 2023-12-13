#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum action {
    EXIT,
    GET_ORDER,
    SHOW_CLIENT_ORDER,
    SHOW_PENDING_ORDERS,
    SAVE_PENDING,
    LOAD_PENDING,
    READY_PENDING_ORDERS,
    SHOW_READY_ORDERS,
    CLOSE_READY_ORDER,
    SHOW_CLOSED_ORDERS
};

typedef struct orderCost {
    float firstCost;
    float finalCost;
    int discount;
} Cost;

typedef struct orderDetails {
    char name[50];
    char startDate[20];
    char deadLine[20];
    char endDate[20];
    Cost orderCost;
    int smallBottles;
    int bigBottles;
    int orderNumber;
    char orderStatus[20];
} Details;


Details getOrder(int numOrders, int *orderCounter);
Cost getOrderCost(int bigBottles, int smallBottles);
Details finishPendingOrder(Details pendingOrderArray[], int *numPendingOrders);
Details closeReadyOrder(Details readyOrderArray[], int *numReadyOrders);

void showClientOrder(Details pendingOrderArray[], int numPendingOrders);
void getCurrentDate();
void showOrders(Details OrderArray[], int numOrders);

int main() {
    // Set variables
    int action = -1;
    int numPendingOrders = 0;
    int numReadyOrders = 0;
    int numClosedOrders = 0;
    int orderCounter = 1;
    
    Details pendingOrderArray[100]; // Assuming a maximum of 100 orders
	Details readyOrderArray[100];
	Details closedOrderArray[100];
	
    while (action != 0) {
        // Get action
        
        printf("Exit: 0\n");
		printf("Get order: 1\n");
		printf("Show client orders: 2\n");
		printf("Show Pending Orders: 3\n");
		//printf("Save pending orders: 4\n");
		//printf("Load pending order: 5\n");
		printf("Ready order: 6\n");
		printf("Show ready orders: 7\n");
		printf("Close order: 8\n");
		printf("Show closed order: 9\n");
		
        printf("Enter action:\n");
        scanf("%d", &action);

        // Set logic gate
        switch (action) {
            case EXIT:
                return 0;
            case GET_ORDER:
                if (numPendingOrders < 100) {
                    pendingOrderArray[numPendingOrders++] = getOrder(numPendingOrders, &orderCounter);
                } else {
                    printf("Maximum number of orders reached.\n");
                }
                break;
            case SHOW_CLIENT_ORDER:
                showClientOrder(pendingOrderArray, numPendingOrders);
                break;
            case SHOW_PENDING_ORDERS:
                showOrders(pendingOrderArray, numPendingOrders);
                break;
            case SAVE_PENDING:
                //savePendingOrders(orderArray, numOrders);
                break;
            case LOAD_PENDING:
                //loadPendingOrders(orderArray, &numOrders);
                break;
            case READY_PENDING_ORDERS:
            	if (numPendingOrders <= 0) {
        			printf("No pending orders to remove.\n");
        			break;
    			}
            	readyOrderArray[numReadyOrders++] = finishPendingOrder(pendingOrderArray, &numPendingOrders);
                break;
            case SHOW_READY_ORDERS:
            	showOrders(readyOrderArray, numReadyOrders);
            	break;
            case CLOSE_READY_ORDER:
            	if (numReadyOrders <= 0) {
        			printf("No ready orders to remove.\n");
        			break;
    			}
            	closedOrderArray[numClosedOrders++] = closeReadyOrder(readyOrderArray, &numReadyOrders);
            	break;
            case SHOW_CLOSED_ORDERS:
            	showOrders(closedOrderArray, numClosedOrders);
            	break;
            default:
                printf("Invalid action.\n");
                break;
    	}
    }
    return 0;
}

Details getOrder(int numPendingOrders, int *orderCounter) {
	//Struct variable
	Details currentOrder;
	//Other variables
	char startDate[20];
	
	//Get the first part of details
	printf("Enter Small Bottles: ");
	scanf("%d", &currentOrder.smallBottles);
	printf("Enter Big Bottles: ");
	scanf("%d", &currentOrder.bigBottles);
	printf("Enter Name of client: ");
	scanf("%s", &currentOrder.name);
	printf("Enter Deadline(DD/MM/YY): ");
	scanf("%s", &currentOrder.deadLine);
	
	//Get the rest of details
	currentOrder.orderNumber = *orderCounter;
	(*orderCounter)++;
	
	//Cost related info
	currentOrder.orderCost = getOrderCost(currentOrder.bigBottles, currentOrder.smallBottles);
	//Time info
	getCurrentDate(startDate);
	strcpy(currentOrder.startDate, startDate);
	strcpy(currentOrder.endDate, "--/--/--");
	//Order Status set to pending
	strcpy(currentOrder.orderStatus, "Pending");
	
	return currentOrder;
}

void showClientOrder(Details orderArray[], int numPendingOrders){
	char clientName[50];
	printf("\nEnter client name: ");
	scanf("%s", &clientName);
	
	for(int i = 0;i < numPendingOrders;i++) {
		if(strcmp(orderArray[i].name, clientName) == 0){
			//Print the details
			printf("Order No.%d Details:\n", orderArray[i].orderNumber);
			printf("\t-Name: %s\n", orderArray[i].name);
			printf("\t-Small Bottles: %d\n", orderArray[i].smallBottles);
			printf("\t-Big Bottles: %d\n", orderArray[i].bigBottles);
			printf("\t-Date Received: %s\n", orderArray[i].startDate);
			printf("\t-Deadline: %s\n", orderArray[i].deadLine);
			printf("\t-Starting Cost: %0.2f\n", orderArray[i].orderCost.firstCost);
			printf("\t-Discount: %d\n", orderArray[i].orderCost.discount);
			printf("\t-Final Cost: %0.2f\n", orderArray[i].orderCost.finalCost);
			printf("\t-Date Delivered: %s\n", orderArray[i].endDate);
			printf("\t-Order Status: %s\n", orderArray[i].orderStatus);
		}
	}
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

void showOrders(Details orderArray[], int numOrders) {
	for(int i = 0; i < numOrders; i++) {
		//Print the details
		printf("Order No.%d Details:\n", orderArray[i].orderNumber);
		printf("\t-Name: %s\n", orderArray[i].name);
		printf("\t-Small Bottles: %d\n", orderArray[i].smallBottles);
		printf("\t-Big Bottles: %d\n", orderArray[i].bigBottles);
		printf("\t-Date Received: %s\n", orderArray[i].startDate);
		printf("\t-Deadline: %s\n", orderArray[i].deadLine);
		printf("\t-Starting Cost: %0.2f\n", orderArray[i].orderCost.firstCost);
		printf("\t-Discount: %d\n", orderArray[i].orderCost.discount);
		printf("\t-Final Cost: %0.2f\n", orderArray[i].orderCost.finalCost);
		printf("\t-Date Delivered: %s\n", orderArray[i].endDate);
		printf("\t-Order Status: %s\n", orderArray[i].orderStatus);
	}
}

Details finishPendingOrder(Details pendingOrderArray[], int *numPendingOrders) {
	//Set variables
	Details readyOrder;
	//Set status to ready
	strcpy(pendingOrderArray[0].orderStatus, "Ready");
	//Store the struct to the order Array
	readyOrder = pendingOrderArray[0];
    // Shift elements to fill the gap
    for (int i = 0; i < *numPendingOrders - 1; i++) {
        pendingOrderArray[i] = pendingOrderArray[i + 1];
    }
    // Decrement the count of pending orders
    (*numPendingOrders)--;
	return readyOrder;
}

Details closeReadyOrder(Details readyOrderArray[], int *numReadyOrders) {
	//Set variables
	char endDate[20];
	int orderId;
	int arrayPosition;
	Details closedOrder;
	
	printf("Enter order id: ");
	scanf("%d", &orderId);
	
	for(int i = 0; i < *numReadyOrders; i++) {
		if(readyOrderArray[i].orderNumber == orderId){
			//Get the position in array
			arrayPosition = i;
			//Get date of end
			getCurrentDate(endDate);
			strcpy(readyOrderArray[i].endDate, endDate);
			//Set status to closed
			strcpy(readyOrderArray[i].orderStatus, "Closed");
			closedOrder = readyOrderArray[i];
		} 
	}
	//Shift orders after this one to the left
	for (int i = arrayPosition; i < *numReadyOrders - 1; i++) {
        readyOrderArray[i] = readyOrderArray[i + 1];
    }
	(*numReadyOrders)--;
	
	return closedOrder;
}



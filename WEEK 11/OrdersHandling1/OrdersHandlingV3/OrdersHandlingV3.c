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
    SHOW_CLOSED_ORDERS,
    SAVE_CLOSED_ORDERS,
    LOAD_CLOSED_ORDERS
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
    char orderStatus[20];
    Cost orderCost;
    int smallBottles;
    int bigBottles;
    int orderNumber;
} Details;

//Set prototypes for functions
int menu();
void allocateArrayMemory(Details **orderArray, int *arrayItemCounter);
void getOrderStats(Details *orderArray, int arrayItemCounter);
void getOrder();
void printDetails(Details order);
void showClientOrder(Details *orderArray, int arrayItemCounter);
void showOrderArray(Details *orderArray, int arrayItemCounter);
void getCurrentDate(char startDate[20]);
void readyOrder();
void closeOrder();
void calculateDiscountAndFinalCost(Cost *orderCost, int smallBottles, int bigBottles);

//Set global arrays for better data sharing
Details *pendingOrderArray;
Details *readyOrderArray;
Details *closedOrderArray;

//Set global array item counters
int numPendingOrder = 0;
int numReadyOrder = 0;
int numClosedOrder = 0;
int orderCounter = 0;

int main() {
	int switchMenu = -1;
	
	while(switchMenu!=0) {
		switchMenu = menu();
	}
	return 0;
}

int menu(){
	int action;
	
	// Get action
    printf("\nExit: 0\n");
	printf("Get order: 1\n");
	printf("Show client orders: 2\n");
	printf("Show Pending Orders: 3\n");
	printf("Save pending orders: 4\n");
	printf("Load pending order: 5\n");
	printf("Ready order: 6\n");
	printf("Show ready orders: 7\n");
	printf("Close order: 8\n");
	printf("Show closed order: 9\n");
	printf("Save closed orders: 10\n");
	printf("Load closed orders: 11\n");
		
    printf("Enter action: ");
    scanf("%d", &action);

    // Set logic gate
    switch (action) {
        case EXIT:
            return 0;
        case GET_ORDER:
        	getOrder();
            break;
        case SHOW_CLIENT_ORDER:
        	showClientOrder(pendingOrderArray, numPendingOrder);
            break;
        case SHOW_PENDING_ORDERS:
        	showOrderArray(pendingOrderArray, numPendingOrder);
            break;
        case SAVE_PENDING:
			break;
        case LOAD_PENDING:
            break;
        case READY_PENDING_ORDERS:
        	readyOrder();
            break;
        case SHOW_READY_ORDERS:
        	showOrderArray(readyOrderArray, numReadyOrder);
        	break;
        case CLOSE_READY_ORDER:
        	closeOrder();
            break;
        case SHOW_CLOSED_ORDERS:
        	showOrderArray(closedOrderArray, numClosedOrder);
            break;
        case SAVE_CLOSED_ORDERS:
        	break;
        case LOAD_CLOSED_ORDERS:
            break;
        default:
            printf("Invalid action.\n");
            break;
    	}
    return 1;
}

void allocateArrayMemory(Details **orderArray, int *arrayItemCounter) {
    *orderArray = (Details *)realloc(*orderArray, sizeof(Details) * (*arrayItemCounter + 1));

    if (*orderArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit on failure
    }

    (*arrayItemCounter)++;
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

void getOrderStats(Details *orderArray, int arrayItemCounter) {
	char startDate[20];
	
	//Variables you assign
	printf("Enter Name of client: ");
    scanf("%s", orderArray[arrayItemCounter-1].name);
    printf("Enter Small Bottles: ");
    scanf("%d", &orderArray[arrayItemCounter-1].smallBottles);
    printf("Enter Big Bottles: ");
    scanf("%d", &orderArray[arrayItemCounter-1].bigBottles);
    printf("Enter Deadline(DD/MM/YY): ");
    scanf("%s", orderArray[arrayItemCounter-1].deadLine);
    
    //Automatic variable assignment
    orderArray[arrayItemCounter-1].orderNumber = orderCounter;
    strcpy(orderArray[arrayItemCounter-1].orderStatus, "Pending");
    orderArray[arrayItemCounter-1].orderCost.discount = 0;
    orderArray[arrayItemCounter-1].orderCost.firstCost = 0;
    orderArray[arrayItemCounter-1].orderCost.finalCost = 0;
    //Time info
	getCurrentDate(startDate);
	strcpy(orderArray[arrayItemCounter-1].startDate, startDate);
	strcpy(orderArray[arrayItemCounter-1].endDate, "--/--/--");
}

void getOrder(){
	allocateArrayMemory(&pendingOrderArray, &numPendingOrder);
	orderCounter++;
    getOrderStats(pendingOrderArray, numPendingOrder);
}

void printDetails(Details order){
	//PrarrayItemPositionnt the details
	printf("Order No.%d Details:\n", order.orderNumber);
	printf("\t-Name: %s\n", order.name);
	printf("\t-Small Bottles: %d\n", order.smallBottles);
	printf("\t-Big Bottles: %d\n", order.bigBottles);
	printf("\t-Date Received: %s\n", order.startDate);
	printf("\t-Deadline: %s\n", order.deadLine);
	printf("\t-Starting Cost: %0.2f\n", order.orderCost.firstCost);
	printf("\t-Discount: %d\n", order.orderCost.discount);
	printf("\t-Final Cost: %0.2f\n", order.orderCost.finalCost);
	printf("\t-Date Delivered: %s\n", order.endDate);
	printf("\t-Order Status: %s\n", order.orderStatus);
}

void showClientOrder(Details *orderArray, int arrayItemCounter){
	char clientName[50];
	printf("Enter client name: ");
	scanf("%s", &clientName);
	
	for(int i = 0;i < arrayItemCounter;i++) {
		if(strcmp(orderArray[i].name, clientName) == 0){
			printDetails(orderArray[i]);	
		}
	}
}

void showOrderArray(Details *orderArray, int arrayItemCounter){
	for(int i = 0; i < arrayItemCounter; i++) {
		printDetails(orderArray[i]);
	}
}

void readyOrder() {
	if(numPendingOrder == 0){
		printf("No pending orders to mark as ready.\n");
		return;
	}
	
	// Allocate memory for the ready array
	allocateArrayMemory(&readyOrderArray, &numReadyOrder);
	
	// Copy the order to the ready array
	readyOrderArray[numReadyOrder - 1] = pendingOrderArray[0];

	// Update the order status and cost in the ready array
	strcpy(readyOrderArray[numReadyOrder - 1].orderStatus, "Ready");
	readyOrderArray[numReadyOrder - 1].orderCost.firstCost = readyOrderArray[numReadyOrder - 1].bigBottles * 0.02 + readyOrderArray[numReadyOrder - 1].smallBottles * 0.008;

    // Shift elements in the pending array to the left
    for (int i = 0; i < numPendingOrder - 1; i++) {
        pendingOrderArray[i] = pendingOrderArray[i + 1];
    }

    // Decrement the number of pending orders
    numPendingOrder--;
    // Reallocate memory for the pending array
    pendingOrderArray = (Details *)realloc(pendingOrderArray, sizeof(Details) * numPendingOrder);
    if (pendingOrderArray == NULL && numPendingOrder > 0) {
        fprintf(stderr, "Memory reallocation failed for pendingOrderArray\n");
        exit(1);
    }
}

void closeOrder() {
	char endDate[20];
	
	if(numReadyOrder == 0){
		printf("No ready orders to mark as closed.\n");
		return;
	}
	
	// Allocate memory for the ready array
	allocateArrayMemory(&closedOrderArray, &numClosedOrder);
	
	// Copy the order to the ready array
	closedOrderArray[numClosedOrder - 1] = readyOrderArray[0];

	// Update the order status and cost in the ready array
	strcpy(closedOrderArray[numClosedOrder - 1].orderStatus, "Closed");
	calculateDiscountAndFinalCost(&closedOrderArray[numClosedOrder - 1].orderCost, closedOrderArray[numClosedOrder - 1].smallBottles, closedOrderArray[numClosedOrder - 1].bigBottles);
    //Time info
	getCurrentDate(endDate);
	strcpy(closedOrderArray[numClosedOrder-1].endDate, endDate);
	// Shift elements in the pending array to the left
    for (int i = 0; i < numReadyOrder - 1; i++) {
        readyOrderArray[i] = readyOrderArray[i + 1];
    }

    // Decrement the number of pending orders
    numReadyOrder--;
    // Reallocate memory for the pending array
    readyOrderArray = (Details *)realloc(readyOrderArray, sizeof(Details) * numReadyOrder);
    if (readyOrderArray == NULL && numReadyOrder > 0) {
        fprintf(stderr, "Memory reallocation failed for readyOrderArray\n");
        exit(1);
    }
}

void calculateDiscountAndFinalCost(Cost *orderCost, int smallBottles, int bigBottles) {
    float firstCost = orderCost->firstCost;

    if (firstCost > 600) {
        orderCost->discount = 20;
        orderCost->finalCost = firstCost * 0.8;
    } else if (firstCost > 200 || (smallBottles + bigBottles) > 3000) {
        orderCost->discount = 8;
        orderCost->finalCost = firstCost * 0.92;
    } else {
        orderCost->discount = 0;
        orderCost->finalCost = firstCost;
    }
}

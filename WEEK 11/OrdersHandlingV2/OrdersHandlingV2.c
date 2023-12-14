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
void printDetails(Details *orderArray, int arrayItemPosition);
void showClientOrder(Details *orderArray, int arrayItemCounter);
void showOrderArray(Details *orderArray, int arrayItemCounter);
void getCurrentDate(char startDate[20]);

//Set global arrays for better data sharing
Details *pendingOrderArray;

//Set global array item counters
int numPendingOrder;

int main() {
	int action = -1;
	
	while(action!=0) {
		action = menu();
	}
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
            break;
        case CLOSE_READY_ORDER:
            break;
        case SHOW_CLOSED_ORDERS:
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
    orderArray[arrayItemCounter-1].orderNumber = arrayItemCounter;
    strcpy(orderArray[arrayItemCounter-1].orderStatus, "Pending");
    //Time info
	getCurrentDate(startDate);
	strcpy(orderArray[arrayItemCounter-1].startDate, startDate);
	strcpy(orderArray[arrayItemCounter-1].endDate, "--/--/--");
}

void getOrder(){
	allocateArrayMemory(&pendingOrderArray, &numPendingOrder);
    getOrderStats(pendingOrderArray, numPendingOrder);
}

void printDetails(Details *orderArray, int arrayItemPosition){
	//PrarrayItemPositionnt the details
	printf("Order No.%d Details:\n", orderArray[arrayItemPosition].orderNumber);
	printf("\t-Name: %s\n", orderArray[arrayItemPosition].name);
	printf("\t-Small Bottles: %d\n", orderArray[arrayItemPosition].smallBottles);
	printf("\t-Big Bottles: %d\n", orderArray[arrayItemPosition].bigBottles);
	printf("\t-Date Received: %s\n", orderArray[arrayItemPosition].startDate);
	printf("\t-Deadline: %s\n", orderArray[arrayItemPosition].deadLine);
	printf("\t-Starting Cost: %0.2f\n", orderArray[arrayItemPosition].orderCost.firstCost);
	printf("\t-Discount: %d\n", orderArray[arrayItemPosition].orderCost.discount);
	printf("\t-Final Cost: %0.2f\n", orderArray[arrayItemPosition].orderCost.finalCost);
	printf("\t-Date Delivered: %s\n", orderArray[arrayItemPosition].endDate);
	printf("\t-Order Status: %s\n", orderArray[arrayItemPosition].orderStatus);

}

void showClientOrder(Details *orderArray, int arrayItemCounter){
	char clientName[50];
	printf("Enter client name: ");
	scanf("%s", &clientName);
	
	for(int i = 0;i < arrayItemCounter;i++) {
		if(strcmp(orderArray[i].name, clientName) == 0){
			printDetails(orderArray, i);	
		}
	}
}

void showOrderArray(Details *orderArray, int arrayItemCounter){
	for(int i = 0; i < arrayItemCounter; i++) {
		printDetails(orderArray, i);
	}
}


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
void showOrders(Details orderArray[], int numOrders);
void saveOrdersToFile(Details orderArray[], int numOrders, const char *filename);
void loadAndUpdateOrders(Details orderArray[], int *numOrders, const char *filename);
void sortClosedArray(Details closedArray[], int numOrders);
void saveOrdersToTextFile(Details orderArray[], int numOrders, const char *filename);

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
		printf("Save pending orders: 4\n");
		printf("Load pending order: 5\n");
		printf("Ready order: 6\n");
		printf("Show ready orders: 7\n");
		printf("Close order: 8\n");
		printf("Show closed order: 9\n");
		printf("Save closed orders: 10\n");
		printf("Load closed orders: 11\n");
		
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
				saveOrdersToFile(pendingOrderArray, numPendingOrders, "pending_orders.dat");
				saveOrdersToTextFile(pendingOrderArray, numPendingOrders, "text_pending_orders.txt");
                break;
            case LOAD_PENDING:
                loadAndUpdateOrders(pendingOrderArray, &numPendingOrders, "pending_orders.dat");
                orderCounter = pendingOrderArray[numPendingOrders].orderNumber;
                break;
            case READY_PENDING_ORDERS:
            	if (numPendingOrders <= 0) {
        			printf("No pending orders to remove.\n");
        			break;
    			}
    			else if(numReadyOrders < 100) {
    				readyOrderArray[numReadyOrders++] = finishPendingOrder(pendingOrderArray, &numPendingOrders);
				}
				else {
					printf("Maximum number of ready orders reached.");
				}
                break;
            case SHOW_READY_ORDERS:
            	showOrders(readyOrderArray, numReadyOrders);
            	break;
            case CLOSE_READY_ORDER:
            	if (numReadyOrders <= 0) {
        			printf("No ready orders to remove.\n");
        			break;
    			} else if(numClosedOrders < 100) {
    				closedOrderArray[numClosedOrders++] = closeReadyOrder(readyOrderArray, &numReadyOrders);
				}
				else{
					printf("Maximum number of closed orders reached.");
				}
            	break;
            case SHOW_CLOSED_ORDERS:
            	showOrders(closedOrderArray, numClosedOrders);
            	break;
            case SAVE_CLOSED_ORDERS:
            	saveOrdersToFile(closedOrderArray, numClosedOrders, "closed_orders.dat");
            	saveOrdersToTextFile(closedOrderArray, numClosedOrders, "text_closed_orders.txt");
            	break;
            case LOAD_CLOSED_ORDERS:
            	loadAndUpdateOrders(closedOrderArray, &numClosedOrders, "closed_orders.dat");
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
	Details closedOrder;
	//Get date of end
	getCurrentDate(endDate);
	strcpy(readyOrderArray[0].endDate, endDate);
	//Set status to closed
	strcpy(readyOrderArray[0].orderStatus, "Closed");
	closedOrder = readyOrderArray[0];
	//Shift orders after this one to the left
	for (int i = 0; i < *numReadyOrders - 1; i++) {
        readyOrderArray[i] = readyOrderArray[i + 1];
    }
	(*numReadyOrders)--;
	
	return closedOrder;
}

void saveOrdersToFile(Details orderArray[], int numOrders, const char *filename) {
    FILE *file = fopen(filename, "wb");  // Open the file in binary write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write the number of orders to the file
    fwrite(&numOrders, sizeof(int), 1, file);

    // Write the entire array to the file
    fwrite(orderArray, sizeof(Details), numOrders, file);

    fclose(file);  // Close the file
}

void loadAndUpdateOrders(Details orderArray[], int *numOrders, const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open the file in binary read mode

    if (file == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        return;
    }

    // Read the number of orders from the file
    fread(numOrders, sizeof(int), 1, file);

    // Read the entire array from the file
    fread(orderArray, sizeof(Details), *numOrders, file);

    fclose(file);  // Close the file
}

void saveOrdersToTextFile(Details orderArray[], int numOrders, const char *filename) {
    FILE *file = fopen(filename, "w");  // Open the file in text write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write each order to the file in a human-readable format
    for (int i = 0; i < numOrders; ++i) {
        fprintf(file, "Order Number: %d\n", orderArray[i].orderNumber);
        fprintf(file, "Name: %s\n", orderArray[i].name);
        fprintf(file, "Small Bottles: %d\n", orderArray[i].smallBottles);
        fprintf(file, "Big Bottles: %d\n", orderArray[i].bigBottles);
        fprintf(file, "Start Date: %s\n", orderArray[i].startDate);
        fprintf(file, "Deadline: %s\n", orderArray[i].deadLine);
        fprintf(file, "Starting Cost: %0.2f\n", orderArray[i].orderCost.firstCost);
        fprintf(file, "Discount: %d\n", orderArray[i].orderCost.discount);
        fprintf(file, "Final Cost: %0.2f\n", orderArray[i].orderCost.finalCost);
        fprintf(file, "End Date: %s\n", orderArray[i].endDate);
        fprintf(file, "Order Status: %s\n", orderArray[i].orderStatus);
        fprintf(file, "\n");  // Add a separator between orders
    }

    fclose(file);  // Close the file
}


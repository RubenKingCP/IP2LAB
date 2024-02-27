#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


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
} Details;

//Set prototypes for functions
int menu();
void allocateArrayMemory(Details **orderArray, int *arrayItemCounter);
void getOrderStats(Details *orderArray[100], int arrayItemCounter);
void getOrder();
void printDetails(Details *order);
void showClientOrder(Details *orderArray[100], int arrayItemCounter);
void showOrderArray(Details *orderArray[100], int arrayItemCounter);
void getCurrentDate(char startDate[20]);
int getIntegerInput(int *value);
bool checkValidDate(char date[10]);
void readyOrder();
void closeOrder();
void calculateDiscountAndFinalCost(Cost *orderCost, int smallBottles, int bigBottles);
void saveOrdersToBinaryFile(Details *orderArray[100], int numOrders, const char *filename);
void saveOrdersToTXTFile(Details *orderArray[100], int numOrders, const char *filename);
void loadOrdersFromFile(Details *orderArray[100], int *numOrders, const char *filename);


//Set global arrays for better data sharing
Details *pendingOrderArray[100];
Details *readyOrderArray[100];
Details *closedOrderArray[100];



//Set global array item counters
int numPendingOrder = 0;
int numReadyOrder = 0;
int numClosedOrder = 0;

int main() {
	int  choice = -1;
	
	while((choice = menu())!=EXIT) {
		 // Set logic gate
	    switch (choice) {
	        case EXIT:
	            return 0;
	        case GET_ORDER:
	        	getOrder();
	            break;
	        case SHOW_CLIENT_ORDER:
	        	showClientOrder(pendingOrderArray, numPendingOrder);
	            break;
	        case SHOW_PENDING_ORDERS:
	        	printf("Pending Orders Details.\n");
	        	showOrderArray(pendingOrderArray, numPendingOrder);
	            break;
	        case SAVE_PENDING:
	        	saveOrdersToBinaryFile(pendingOrderArray, numPendingOrder, "pending-file.dat");
	        	saveOrdersToTXTFile(pendingOrderArray, numPendingOrder, "pending-file.txt");
				break;
	        case LOAD_PENDING:
	        	loadOrdersFromFile(pendingOrderArray, &numPendingOrder, "pending-file.dat");
	            break;
	        case READY_PENDING_ORDERS:
	        	readyOrder();
	            break;
	        case SHOW_READY_ORDERS:
	        	printf("Ready Orders Details:\n");
	        	showOrderArray(readyOrderArray, numReadyOrder);
	        	break;
	        case CLOSE_READY_ORDER:
	        	closeOrder();
	            break;
	        case SHOW_CLOSED_ORDERS:
	        	printf("Closed Orders Details:\n");
	        	showOrderArray(closedOrderArray, numClosedOrder);
	            break;
	        case SAVE_CLOSED_ORDERS:
	        	saveOrdersToBinaryFile(closedOrderArray, numClosedOrder, "closed-file.dat");
	        	saveOrdersToTXTFile(closedOrderArray, numClosedOrder, "closed-file.txt");
	        	break;
	        case LOAD_CLOSED_ORDERS:
	        	loadOrdersFromFile(closedOrderArray, &numClosedOrder, "closed-file.dat");
	        	break;
	        default:
	            printf("Invalid action.\n");
	            break;
	    	}
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
    return action;
}

void allocateArrayMemory(Details **orderArray, int *arrayItemCounter) {
    orderArray = (Details **)realloc(*orderArray, sizeof(Details *) * (*arrayItemCounter + 1));

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

void getOrderStats(Details *orderArray[100], int arrayItemCounter) {
	char startDate[20];
	int result;
	
	printf("Enter Name of client: ");
	if (scanf(" %[^\n]", orderArray[arrayItemCounter-1]->name) != 1) {
    	printf("Error reading input.\n");
    	// Handle the error, maybe clear the input buffer or take appropriate action
	}
    //Set failsafes
    do {
    	printf("Enter small bottles: ");
        result = getIntegerInput(&orderArray[arrayItemCounter-1]->smallBottles);
    } while (result != 1);
    
    do {
    	printf("Enter big bottles: ");
        result = getIntegerInput(&orderArray[arrayItemCounter-1]->bigBottles);
    } while (result != 1);
    
    do{
    	printf("Enter Deadline(DD/MM/YY): ");
    	scanf("%s", orderArray[arrayItemCounter-1]->deadLine);
	} while(!checkValidDate(orderArray[arrayItemCounter-1]->deadLine));
    
    //Automatic variable assignment
    strcpy(orderArray[arrayItemCounter-1]->orderStatus, "Pending");
    orderArray[arrayItemCounter-1]->orderCost.discount = 0;
    orderArray[arrayItemCounter-1]->orderCost.firstCost = 0;
    orderArray[arrayItemCounter-1]->orderCost.finalCost = 0;
    //Time info
	getCurrentDate(startDate);
	strcpy(orderArray[arrayItemCounter-1]->startDate, startDate);
	strcpy(orderArray[arrayItemCounter-1]->endDate, "--/--/--");
}

int getIntegerInput(int *value) {
    int result;
    char input[20];

    result = scanf("%s", input);

    int i = 0;

    // Check if the input contains both numbers and letters
    while (input[i] != '\0') {
    	//Check if it's not a digit
        if (!isdigit(input[i])) {
            result = 0; // Set result to 0 to repeat the loop
            printf("Invalid input. Please enter a valid number.\n");

            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            return 0;
        }
        i++;
    }

    // Convert the valid input to an integer
    sscanf(input, "%d", value);

    return result;
}

bool checkValidDate(char date[10]){
	int day, month, year;
	sscanf(date, "%d/%d/%d", &day, &month, &year);
	if(day < 0 || day > 31) {
		printf("Invalid date. Enter a valid one.\n");
		return false;
	}
	if(month < 0 || month > 12){
		printf("Invalid date. Enter a valid one.\n");
		return false;
	}
	if(year < 0 || year > 100){
		printf("Invalid date. Enter a valid one.\n");
		return false;
	}
	return true;
}

void getOrder() {
    // Allocate memory for each new order separately
    Details *newOrder = (Details *)malloc(sizeof(Details));
    if (newOrder == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit on failure
    }

    // Pass the address of the newOrder pointer to getOrderStats
    getOrderStats(&newOrder, 1);

    // Allocate memory for the pending order array
    allocateArrayMemory(pendingOrderArray, &numPendingOrder);

    // Add the new order to the pending order array
    pendingOrderArray[numPendingOrder - 1] = newOrder;
}

void printDetails(Details *order){
	//Print the details
	printf("\t-Name: %s\n", order->name);
	printf("\t-Small Bottles: %d\n", order->smallBottles);
	printf("\t-Big Bottles: %d\n", order->bigBottles);
	printf("\t-Date Received: %s\n", order->startDate);
	printf("\t-Deadline: %s\n", order->deadLine);
	printf("\t-Starting Cost: %0.2f\n", order->orderCost.firstCost);
	printf("\t-Discount: %d\n", order->orderCost.discount);
	printf("\t-Final Cost: %0.2f\n", order->orderCost.finalCost);
	printf("\t-Date Delivered: %s\n", order->endDate);
	printf("\t-Order Status: %s\n\n", order->orderStatus);
}

void showClientOrder(Details *orderArray[100], int arrayItemCounter){
	char clientName[50];
	printf("Enter client name: ");
	scanf("%s", &clientName);
	
	for(int i = 0;i < arrayItemCounter;i++) {
		if(strcmp(orderArray[i]->name, clientName) == 0){
			printDetails(orderArray[i]);	
		}
	}
}

void showOrderArray(Details *orderArray[100], int arrayItemCounter){
	for(int i = 0; i < arrayItemCounter; i++) {
		printDetails(orderArray[i]);
	}
}

void readyOrder() {
    if (numPendingOrder == 0) {
        printf("No pending orders to mark as ready.\n");
        return;
    }

    // Allocate memory for the ready array
    allocateArrayMemory(readyOrderArray, &numReadyOrder);

    // Allocate memory for the new order in the ready array
    readyOrderArray[numReadyOrder - 1] = (Details *)malloc(sizeof(Details));

    if (readyOrderArray[numReadyOrder - 1] == NULL) {
        fprintf(stderr, "Memory allocation failed for readyOrderArray\n");
        exit(1);
    }

    // Copy the order to the ready array
    memcpy(readyOrderArray[numReadyOrder - 1], pendingOrderArray[0], sizeof(Details));

    // Update the order status and cost in the ready array
    strcpy(readyOrderArray[numReadyOrder - 1]->orderStatus, "Ready");
    readyOrderArray[numReadyOrder - 1]->orderCost.firstCost =
        readyOrderArray[numReadyOrder - 1]->bigBottles * 0.02 + readyOrderArray[numReadyOrder - 1]->smallBottles * 0.008;

    // Free the memory for the order in the pending array
    free(pendingOrderArray[0]);

    // Shift elements in the pending array to the left
    for (int i = 0; i < numPendingOrder - 1; i++) {
        pendingOrderArray[i] = pendingOrderArray[i + 1];
    }

    // Decrement the number of pending orders
    numPendingOrder--;

    // Reallocate memory for the pending array
    *pendingOrderArray = (Details *)realloc(pendingOrderArray, sizeof(Details) * numPendingOrder);

    if (*pendingOrderArray == NULL && numPendingOrder > 0) {
        fprintf(stderr, "Memory reallocation failed for pendingOrderArray\n");
        exit(1);
    }
}

void closeOrder() {
    char endDate[20];

    if (numReadyOrder == 0) {
        printf("No ready orders to mark as closed.\n");
        return;
    }

    // Allocate memory for the closed array
    allocateArrayMemory(closedOrderArray, &numClosedOrder);

    // Allocate memory for the new order in the closed array
    closedOrderArray[numClosedOrder - 1] = (Details *)malloc(sizeof(Details));

    if (closedOrderArray[numClosedOrder - 1] == NULL) {
        fprintf(stderr, "Memory allocation failed for closedOrderArray\n");
        exit(1);
    }

    // Copy the order to the closed array
    memcpy(closedOrderArray[numClosedOrder - 1], readyOrderArray[0], sizeof(Details));

    // Update the order status and cost in the closed array
    strcpy(closedOrderArray[numClosedOrder - 1]->orderStatus, "Closed");
    calculateDiscountAndFinalCost(&closedOrderArray[numClosedOrder - 1]->orderCost,
                                  closedOrderArray[numClosedOrder - 1]->smallBottles,
                                  closedOrderArray[numClosedOrder - 1]->bigBottles);

    // Time info
    getCurrentDate(endDate);
    strcpy(closedOrderArray[numClosedOrder - 1]->endDate, endDate);

    // Free the memory for the order in the ready array
    free(readyOrderArray[0]);

    // Shift elements in the ready array to the left
    for (int i = 0; i < numReadyOrder - 1; i++) {
        readyOrderArray[i] = readyOrderArray[i + 1];
    }

    // Decrement the number of ready orders
    numReadyOrder--;

    // Reallocate memory for the ready array
    *readyOrderArray = (Details *)realloc(readyOrderArray, sizeof(Details) * numReadyOrder);

    if (*readyOrderArray == NULL && numReadyOrder > 0) {
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

void saveOrdersToBinaryFile(Details *orderArray[100], int numOrders, const char *filename) {
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

void saveOrdersToTXTFile(Details *orderArray[100], int numOrders, const char *filename) {
    FILE *file = fopen(filename, "w");  // Open the file in write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write each order's details to the file
    for (int i = 0; i < numOrders; ++i) {
        fprintf(file, "\t-Name: %s\n", orderArray[i]->name);
        fprintf(file, "\t-Small Bottles: %d\n", orderArray[i]->smallBottles);
        fprintf(file, "\t-Big Bottles: %d\n", orderArray[i]->bigBottles);
        fprintf(file, "\t-Date Received: %s\n", orderArray[i]->startDate);
        fprintf(file, "\t-Deadline: %s\n", orderArray[i]->deadLine);
        fprintf(file, "\t-Starting Cost: %0.2f\n", orderArray[i]->orderCost.firstCost);
        fprintf(file, "\t-Discount: %d\n", orderArray[i]->orderCost.discount);
        fprintf(file, "\t-Final Cost: %0.2f\n", orderArray[i]->orderCost.finalCost);
        fprintf(file, "\t-Date Delivered: %s\n", orderArray[i]->endDate);
        fprintf(file, "\t-Order Status: %s\n", orderArray[i]->orderStatus);
        fprintf(file, "\n");
    }

    fclose(file);  // Close the file
}

void loadOrdersFromFile(Details *orderArray[100], int *numOrders, const char *filename) {
    FILE *file = fopen(filename, "rb");  // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read the number of orders from the file
    fread(numOrders, sizeof(int), 1, file);

    // Allocate memory for the order array
    *orderArray = (Details *)malloc(sizeof(Details) * (*numOrders));

    if (*orderArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);  // Exit on failure
    }

    // Read the entire array from the file
    fread(*orderArray, sizeof(Details), *numOrders, file);

    fclose(file);  // Close the file
}


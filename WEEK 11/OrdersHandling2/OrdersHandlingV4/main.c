#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_ORDERS 100

/* TODO
   - ADD POINTERS ARRAY
   - MAKE DATE SYSTEM
   - ADD FAILSAFES
*/

// Setup menu enumeration
enum menu {
    TERMINATE,
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

// Set up struct
typedef struct OrderDetails {
    char name[15];
    char startDate[10];
    char deadline[10];
    char dateDelivered[10];
    int sBottles;
    int bBottles;
    float startingCost;
    float finalCost;
    int discount;
} OrderDetails;

// Set function prototypes
int menu();
OrderDetails* getOrder();
void addOrder(OrderDetails* orderArray[], int *lastOrder, OrderDetails* newOrder);
void getOrderSystem(OrderDetails* orderArray[], int *lastOrder);

// Function to get client orders
void printClientOrders(OrderDetails* orderArray[], int currentOrder, int lastOrder);

// Function to print array
void printArray(OrderDetails* orderArray[], int currentOrder, int lastOrder);

// Ready order
void readyOrder(OrderDetails* pendingOrderArray[], OrderDetails* readyOrderArray[], int *lastReadyOrder, int *currentPendingOrder, int lastPendingOrder);

// Execute order
void closeOrder(OrderDetails* readyOrderArray[], OrderDetails* closedOrderArray[], int *lastClosedOrder, int *currentReadyOrder, int lastReadyOrder);

// Save file
void saveOrdersToFile(OrderDetails *orderArray[MAX_ORDERS], int currentOrder, int lastOrder, const char *filename);
void loadOrdersFromFile(OrderDetails *orderArray[MAX_ORDERS], int *currentOrder, int *lastOrder, const char *filename);

// Failsafes and other stuff
void getCurrentDate(char startDate[10]);
int getIntegerInput(int *value);
bool checkValidDate(char date[10]);

int main() {
    OrderDetails* pendingOrderArray[MAX_ORDERS];
    int currentPendingOrder = 0;
    int lastPendingOrder = 0;

    OrderDetails* readyOrderArray[MAX_ORDERS];
    int currentReadyOrder = 0;
    int lastReadyOrder = 0;

    OrderDetails* closedOrderArray[MAX_ORDERS];
    int lastClosedOrder = 0;
    int temp = 0;

    int choice = -1;

    while ((choice = menu()) != TERMINATE) {
        switch (choice) {
        case TERMINATE:
            return 0;
        case GET_ORDER:
            getOrderSystem(pendingOrderArray, &lastPendingOrder);
            break;
        case SHOW_CLIENT_ORDER:
            printf("PendingOrders\n");
            printClientOrders(pendingOrderArray, currentPendingOrder, lastPendingOrder);
            break;
        case SHOW_PENDING_ORDERS:
            printArray(pendingOrderArray, currentPendingOrder, lastPendingOrder);
            break;
        case SAVE_PENDING:
        	saveOrdersToFile(pendingOrderArray, currentPendingOrder, lastPendingOrder, "pending-order.txt");
            break;
        case LOAD_PENDING:
        	loadOrdersFromFile(pendingOrderArray, &currentPendingOrder, &lastPendingOrder, "pending-order.txt");
            break;
        case READY_PENDING_ORDERS:
            readyOrder(pendingOrderArray, readyOrderArray, &lastReadyOrder, &currentPendingOrder, lastPendingOrder);
            break;
        case SHOW_READY_ORDERS:
            printf("Ready Orders:\n");
            printArray(readyOrderArray, currentReadyOrder, lastReadyOrder);
            break;
        case CLOSE_READY_ORDER:
            closeOrder(readyOrderArray, closedOrderArray, &lastClosedOrder, &currentReadyOrder, lastReadyOrder);
            break;
        case SHOW_CLOSED_ORDERS:
            printf("Closed Orders:\n");
            printArray(closedOrderArray, temp, lastClosedOrder);
            break;
        case SAVE_CLOSED_ORDERS:
        	saveOrdersToFile(closedOrderArray, temp, lastClosedOrder, "closed-order.txt");
            break;
        case LOAD_CLOSED_ORDERS:
        	loadOrdersFromFile(closedOrderArray, &temp, &lastClosedOrder, "closed-order.txt");
            break;
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
}

int menu() {
    int choice;

    // Get choice
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
    printf("Load closed orders: 11\n\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

OrderDetails* getOrder() {
    OrderDetails* newOrder = (OrderDetails*)malloc(sizeof(OrderDetails));
    int result;
    char startDate[10];
    
    if (!newOrder) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\nEnter client name: ");
    scanf(" %[^\n]%*c", newOrder->name);
    
    //Set failsafes
    do {
    	printf("Enter small bottles: ");
        result = getIntegerInput(&newOrder->sBottles);
    } while (result != 1);
    
    do {
    	printf("Enter big bottles: ");
        result = getIntegerInput(&newOrder->bBottles);
    } while (result != 1);
    
    do{
    	printf("Enter deadline(DD/MM/YY): ");
    	scanf("%s", newOrder->deadline);
	} while(!checkValidDate(newOrder->deadline));

    // Set the starting values of the rest
    newOrder->startingCost = 0;
    newOrder->finalCost = 0;
    newOrder->discount = 0;
    //Time info
	getCurrentDate(startDate);
	strcpy(newOrder->startDate, startDate);
	strcpy(newOrder->dateDelivered, "--/--/--");

    return newOrder;
}

void addOrder(OrderDetails* orderArray[MAX_ORDERS], int* lastOrder, OrderDetails* newOrder) {
    int index = *lastOrder % MAX_ORDERS;  // Circular indexing(returns the remainder of lastOrder / 100)
    orderArray[index] = newOrder;
    (*lastOrder)++;
}

void getOrderSystem(OrderDetails* orderArray[], int* lastPendingOrder) {
    OrderDetails* newOrder = getOrder();
    addOrder(orderArray, lastPendingOrder, newOrder);
}

void printOrder(OrderDetails* order) {
    printf("%-15s\t", order->name);
    printf("%-10d\t", order->sBottles);
    printf("%-10d\t", order->bBottles);
    printf("%-10.2f", order->startingCost);
    printf("%-10.2f\t", order->finalCost);
    printf("%-4d\t", order->discount);
    printf("%-10s\t", order->startDate);
    printf("%-10s\t", order->deadline);
    printf("%-10s\n", order->dateDelivered);
}

void printArray(OrderDetails* orderArray[], int currentOrder, int lastOrder) {
    if (currentOrder == lastOrder) {
        printf("No orders to show.\n\n");
        return;
    }
    for (int i = currentOrder; i < lastOrder; i++) {
        printf("Order %d: ", i + 1);
        printOrder(orderArray[i]);
    }
}

void printClientOrders(OrderDetails* orderArray[], int numOrder, int lastOrder) {
    // Other variables
    int found = 0;
    int orderCount = 1;
    // Get client name
    char name[15];
    printf("Enter client name: ");
    scanf(" %[^\n]", name);
    // Check for order
    printf("Client's %s orders:\n", name);
    for (int i = lastOrder; i < numOrder; i++) {
        if (strcmp(name, orderArray[i]->name) == 0) {
            printf("Order %d:", orderCount++);
            printOrder(orderArray[i]);
            found = 1;
        }
    }
    if (found == 0) {
        printf(" No orders found.\n");
    }
}

OrderDetails* calculateSum(OrderDetails* pendingOrderArray[], int currentPendingOrder) {
    float sum;
    sum = pendingOrderArray[currentPendingOrder]->bBottles * 0.02 + pendingOrderArray[currentPendingOrder]->sBottles * 0.002;
    pendingOrderArray[currentPendingOrder]->startingCost = sum;
    return pendingOrderArray[currentPendingOrder];
}

void readyOrder(OrderDetails* pendingOrderArray[], OrderDetails* readyOrderArray[], int* lastReadyOrder, int* currentPendingOrder, int lastPendingOrder) {
    if (*currentPendingOrder == lastPendingOrder) {
        printf("No orders to ready.\n");
        return;
    }
    OrderDetails* order = calculateSum(pendingOrderArray, *currentPendingOrder);
    addOrder(readyOrderArray, lastReadyOrder, order);
    (*currentPendingOrder)++;
}

OrderDetails* calculateFinalSum(OrderDetails* readyOrderArray[], int currentReadyOrder) {
    int totalBottles;
    float sum;
    totalBottles = readyOrderArray[currentReadyOrder]->bBottles + readyOrderArray[currentReadyOrder]->sBottles;
    sum = readyOrderArray[currentReadyOrder]->startingCost;
    if (sum > 600) {
        readyOrderArray[currentReadyOrder]->discount = 20;
        readyOrderArray[currentReadyOrder]->finalCost = sum * 0.8;
    } else if (sum > 200 || totalBottles > 3000) {
        readyOrderArray[currentReadyOrder]->discount = 8;
        readyOrderArray[currentReadyOrder]->finalCost = sum * 0.92;
    } else {
        readyOrderArray[currentReadyOrder]->discount = 0;
        readyOrderArray[currentReadyOrder]->finalCost = sum;
    }
    return readyOrderArray[currentReadyOrder];
}

void closeOrder(OrderDetails* readyOrderArray[], OrderDetails* closedOrderArray[], int* lastClosedOrder, int* currentReadyOrder, int lastReadyOrder) {
    if (*currentReadyOrder == lastReadyOrder) {
        printf("No orders to close.\n");
        return;
    }
    char endDate[10];
    OrderDetails* order = calculateFinalSum(readyOrderArray, *currentReadyOrder);
    getCurrentDate(endDate);
    strcpy(order->dateDelivered, endDate);
    addOrder(closedOrderArray, lastClosedOrder, order);
    (*currentReadyOrder)++;
}

void saveOrdersToFile(OrderDetails *orderArray[MAX_ORDERS], int currentOrder, int lastOrder, const char *filename) {
    FILE *file = fopen(filename, "w");  // Open the file in write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Total Orders: %d\n", lastOrder);
    fprintf(file, "Current Orders: %d\n", currentOrder);

    // Write each order's details to the file
    for (int i = currentOrder; i < currentOrder + lastOrder; ++i) {
        int index = i % MAX_ORDERS;  // Circular indexing

        fprintf(file, "%-15s\t", orderArray[index]->name);
        fprintf(file, "%-10d\t", orderArray[index]->sBottles);
        fprintf(file, "%-10d\t", orderArray[index]->bBottles);
        fprintf(file, "%-10.2f", orderArray[index]->startingCost);
        fprintf(file, "%-10.2f\t", orderArray[index]->finalCost);
        fprintf(file, "%-4d\t", orderArray[index]->discount);
        fprintf(file, "%-10s\t", orderArray[index]->startDate);
        fprintf(file, "%-10s\t", orderArray[index]->deadline);
        fprintf(file, "%-10s\n", orderArray[index]->dateDelivered);
    }

    fclose(file);  // Close the file
}

void loadOrdersFromFile(OrderDetails *orderArray[MAX_ORDERS], int *currentOrder, int *lastOrder, const char *filename) {
    FILE *file = fopen(filename, "r");  // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read total and current orders
    fscanf(file, "Total Orders: %d\n", lastOrder);
    fscanf(file, "Current Orders: %d\n", currentOrder);

    // Read each order's details from the file
    for (int i = 0; i < *lastOrder; ++i) {
        // Allocate memory for the next order
        int index = (*currentOrder + i) % MAX_ORDERS;  // Circular indexing
        orderArray[index] = malloc(sizeof(OrderDetails));

        fscanf(file, "%s %d %d %f %f %d %s %s %s",
               orderArray[index]->name,
               &orderArray[index]->sBottles,
               &orderArray[index]->bBottles,
               &orderArray[index]->startingCost,
               &orderArray[index]->finalCost,
               &orderArray[index]->discount,
               orderArray[index]->startDate,
               orderArray[index]->deadline,
               orderArray[index]->dateDelivered);
    }

    fclose(file);  // Close the file
}

void getCurrentDate(char startDate[10]) {
	//Set time variables
	time_t t;
	struct tm *tm_info;
	
	time(&t);//Get the time
	tm_info = localtime(&t); //Convert to format
	
	//Get time in DD/MM/YY format
	strftime(startDate, 10, "%d/%m/%y", tm_info);
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

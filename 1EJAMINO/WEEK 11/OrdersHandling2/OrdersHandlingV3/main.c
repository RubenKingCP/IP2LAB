#include <stdio.h>
#include <string.h>

//Setup menu enumeration
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

//Set up struct
typedef struct OrderDetails {
	char name[15];
	char startDate[20];
	char deadline[20];
	char dateDelivered[20];
	int sBottles;
	int bBottles;
	float startingCost;
	float finalCost;
	int discount;
} OrderDetails;

//Set function prototypes
int menu();

//Functions for gettting order
OrderDetails getOrder();
void addOrder(OrderDetails orderArray[], int *lastOrder, OrderDetails newOrder);
void getOrderSystem(OrderDetails orderArray[], int *lastOrder);

//Function to get client orders
void printClientOrders(OrderDetails orderArray[], int currentOrder, int lastOrder);

//Function to print array
void printArray(OrderDetails orderArray[], int currentOrder, int lastOrder);

//Ready order 
OrderDetails calculate(OrderDetails pendingOrderArray[], int *currentPendingOrder);
void readyOrder(OrderDetails pendingOrderArray[], OrderDetails readyOrderArray[], int *lastReadyOrder, int *currentPendingOrder, int lastPendingOrder);

//Execute order
OrderDetails calculateFinalSum(OrderDetails readyOrderArray[], int currentReadyOrder);
void closeOrder(OrderDetails readyOrderArray[], OrderDetails closedOrderArray[], int *lastClosedOrder, int *currentReadyOrder, int lastReadyOrder);

int main(){
	OrderDetails pendingOrderArray[100];
	int currentPendingOrder = 0;
	int lastPendingOrder = 0;
	OrderDetails readyOrderArray[100];
	int currentReadyOrder = 0;
	int lastReadyOrder = 0;
	OrderDetails closedOrderArray[100];
	int lastClosedOrder = 0;
	
	int choice = -1;
	
	while((choice = menu())!=TERMINATE){
		switch(choice){
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
	        	break;
	        case LOAD_PENDING:
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
	        	printArray(closedOrderArray, 0, lastClosedOrder);
	            break;
	        case SAVE_CLOSED_ORDERS:
	        	break;
	        case LOAD_CLOSED_ORDERS:
	        	break;
			default:
				printf("INVALID CHOICE\n");
				break;
		}
	}
}

int menu(){
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
	printf("Load closed orders: 11\n");
		
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    return choice;
}

OrderDetails getOrder(){
	OrderDetails newOrder;
	
	printf("\nEnter client name: ");
	scanf(" %[^\n]%*c", newOrder.name);
	
	printf("\nEnter amount of small bottles: ");
	scanf("%d", &newOrder.sBottles);
	
	printf("\nEnter amount of big bottles: ");
	scanf("%d", &newOrder.bBottles);
	
	printf("\nEnter deadline(DD/MM/YY): ");
	scanf("%s", newOrder.deadline);
	
	//Set the starting values of the rest
	newOrder.startingCost = 0;
	newOrder.finalCost = 0;
	newOrder.discount = 0;
	strcpy(newOrder.startDate, "00/00/00");
	strcpy(newOrder.dateDelivered, "00/00/00");
	
	return newOrder;
}

void addOrder(OrderDetails orderArray[], int *lastOrder, OrderDetails newOrder){
	orderArray[*lastOrder] = newOrder;
	(*lastOrder)++;
}

void getOrderSystem(OrderDetails orderArray[], int *numOrder){
	OrderDetails newOrder;
	newOrder = getOrder();
	addOrder(orderArray, numOrder, newOrder);
}

void printOrder(OrderDetails order){
	printf("%-15s\t", order.name);
	printf("%-10d\t", order.sBottles);
	printf("%-10d\t", order.bBottles);
	printf("%-10.2f", order.startingCost);
	printf("%-10.2f\t", order.finalCost);
	printf("%-4d\t", order.discount);
	printf("%-10s\t", order.startDate);
	printf("%-10s\t", order.deadline);
	printf("%-10s\n", order.dateDelivered);
}

void printArray(OrderDetails orderArray[], int currentOrder, int lastOrder){
	if(currentOrder == lastOrder){
		printf("No orders to show.\n\n");
		return;
	}
	for(int i = currentOrder; i < lastOrder;i++){
		printf("Order %d: ", i+1);
		printOrder(orderArray[i]);
	}
}

void printClientOrders(OrderDetails orderArray[], int numOrder, int lastOrder){
	//Other variables
	int found = 0;
	int orderCount = 1;
	//Get client name
	char name[15];
	printf("Enter client name: ");
	scanf(" %[^\n]", name);
	//Check for order
	printf("Client's %s orders:\n", name);
	for(int i = lastOrder; i < numOrder;i++){
		if(strcmp(name, orderArray[i].name) == 0){
			printf("Order %d:", orderCount++);
			printOrder(orderArray[i]);
			found = 1;
		}
	}
	if(found == 0){
		printf(" No orders found.\n");
	}
}

OrderDetails calculateSum(OrderDetails pendingOrderArray[], int currentPendingOrder){
	float sum;
	sum = pendingOrderArray[currentPendingOrder].bBottles * 0.02 + pendingOrderArray[currentPendingOrder].sBottles * 0.002;
	pendingOrderArray[currentPendingOrder].startingCost = sum;
	return pendingOrderArray[currentPendingOrder];
}

void readyOrder(OrderDetails pendingOrderArray[], OrderDetails readyOrderArray[], int *lastReadyOrder, int *currentPendingOrder, int lastPendingOrder){
	if(*currentPendingOrder == lastPendingOrder){
		printf("No orders to ready.\n");
		return;
	}
	OrderDetails order;
	order = calculateSum(pendingOrderArray, *currentPendingOrder);
	addOrder(readyOrderArray, lastReadyOrder, order);
	(*currentPendingOrder)++;
}

OrderDetails calculateFinalSum(OrderDetails readyOrderArray[], int currentReadyOrder){
	int totalBottles, sum;
	totalBottles = readyOrderArray[currentReadyOrder].bBottles + readyOrderArray[currentReadyOrder].sBottles;
	sum = readyOrderArray[currentReadyOrder].startingCost;
	if(sum > 600){
		readyOrderArray[currentReadyOrder].discount = 20;
		readyOrderArray[currentReadyOrder].finalCost = sum * 0.8;
	}
	else if(sum > 200 || totalBottles > 3000){
		readyOrderArray[currentReadyOrder].discount = 8;
		readyOrderArray[currentReadyOrder].finalCost = sum * 0.92;
	}
	else{
		readyOrderArray[currentReadyOrder].discount = 0;
		readyOrderArray[currentReadyOrder].finalCost = sum;
	}
	return readyOrderArray[currentReadyOrder];
}

void closeOrder(OrderDetails readyOrderArray[], OrderDetails closedOrderArray[], int *lastClosedOrder, int *currentReadyOrder, int lastReadyOrder){
	if(*currentReadyOrder == lastReadyOrder){
		printf("No orders to close.\n");
		return;
	}
	OrderDetails order;
	order = calculateFinalSum(readyOrderArray, *currentReadyOrder);
	addOrder(closedOrderArray, lastClosedOrder, order);
	(*currentReadyOrder++);
}

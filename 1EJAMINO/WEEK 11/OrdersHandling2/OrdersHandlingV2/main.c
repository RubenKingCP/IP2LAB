#include <stdio.h>
#include <string.h>

//Setup menu enumeration
enum menu {
	TERMINATE,
	GET_ORDER,
	SHOW_CLIENT_ORDER,
	SHOW_PENDING_ORDERS
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
void assignOrderToArray(OrderDetails orderArray[], int *numOrder, OrderDetails newOrder);
void getOrderSystem(OrderDetails orderArray[], int *numOrder);

//Function to get client orders
void printClientOrders(OrderDetails orderArray[], int numOrder);

//Function to print array
void printArray(OrderDetails orderArray[], int numOrder);

int main(){
	OrderDetails pendingOrderArray[100];
	int numPendingOrder = 0;
	
	int choice = -1;
	
	while((choice = menu())!=TERMINATE){
		switch(choice){
			case TERMINATE:
				return 0;
			case GET_ORDER:
				getOrderSystem(pendingOrderArray, &numPendingOrder);
				break;
			case SHOW_CLIENT_ORDER:
				printf("PendingOrders\n");
				printClientOrders(pendingOrderArray, numPendingOrder);
				break;
			case SHOW_PENDING_ORDERS:
				printArray(pendingOrderArray, numPendingOrder);
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

void assignOrderToArray(OrderDetails orderArray[], int *numOrder, OrderDetails newOrder){
	orderArray[*numOrder] = newOrder;
	(*numOrder)++;
}

void getOrderSystem(OrderDetails orderArray[], int *numOrder){
	OrderDetails newOrder;
	newOrder = getOrder();
	assignOrderToArray(orderArray, numOrder, newOrder);
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

void printArray(OrderDetails orderArray[], int numOrder){
	for(int i = 0; i < numOrder;i++){
		printf("Order %d: ", i+1);
		printOrder(orderArray[i]);
	}
}

void printClientOrders(OrderDetails orderArray[], int numOrder){
	//Other variables
	int found = 0;
	int orderCount = 1;
	//Get client name
	char name[15];
	printf("Enter client name: ");
	scanf(" %[^\n]", name);
	//Check for order
	printf("Client's %s orders:\n", name);
	for(int i = 0; i < numOrder;i++){
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

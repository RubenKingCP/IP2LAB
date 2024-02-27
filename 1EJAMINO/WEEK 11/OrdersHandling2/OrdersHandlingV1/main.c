#include <stdio.h>

enum menu {
	TERMINATE,
	GET_ORDER,
	SHOW_CLIENT_ORDER,
	SHOW_PENDING_ORDERS
};

int menu();

int main(){
	int choice = -1;
	
	while((choice = menu())!=TERMINATE){
		switch(choice){
			case TERMINATE:
				return 0;
			case GET_ORDER:
				break;
			case SHOW_CLIENT_ORDER:
				break;
			case SHOW_PENDING_ORDERS:
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
		
    printf("Enter choice:\n");
    scanf("%d", &choice);
    
    return choice;
}

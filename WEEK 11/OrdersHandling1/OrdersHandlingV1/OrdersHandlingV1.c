#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int menu();

int main() {
	int action = -1;
	
	while(action!=0) {
		action = menu();
	}
}

int menu(){
	int action;
	
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
            break;
        case SHOW_CLIENT_ORDER:
            break;
        case SHOW_PENDING_ORDERS:
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

#define STACK_SIZE 50

typedef struct 
{
    int top;
    int stack[STACK_SIZE];
}Stack;


void push(int num, Stack * stack);
int pop(Stack * stack);

void push(int num, Stack *stack) {
    if (stack->top < STACK_SIZE) {  // Check if stack is not full
        stack->stack[stack->top++] = num;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}


int pop(Stack *stack) {
    if (stack->top > 0) {  // Check if stack is not empty
        return stack->stack[--stack->top];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);  // RExit
    }
}

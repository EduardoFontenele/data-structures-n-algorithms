#include <stdio.h>

#define STACK_SIZE 14

typedef struct {
    int top;
    int values[STACK_SIZE - 1];
} stack;

void insert(stack* stack, int val) {
    if (stack->top == STACK_SIZE) {
        printf("Maximum stack size reached\n");
        return;
    }

    stack->top++;
    stack->values[stack->top - 1] = val;
}

void read(stack* stack) {
    printf("%d\n", stack->values[stack->top - 1]);
}

void pop(stack* stack) {
    if (stack->top == 0) {
        stack->values[0] = 0;
        return;
    }

    stack->values[stack->top - 1] = 0;
    stack->top--;
}

int main(int argc, char argv[]) {
    stack stk;

    insert(&stk, 22);
    read(&stk); // prints 22

    insert(&stk, 24);
    insert(&stk, 26);
    insert(&stk, 28);
    read(&stk); // prints 28

    pop(&stk);
    pop(&stk);
    pop(&stk);
    read(&stk); // prints 22

    pop(&stk);
    read(&stk); // prints 0
}
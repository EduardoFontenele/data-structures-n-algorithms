#include <stdio.h>

#define STACK_SIZE 14

typedef struct {
    int beginning_index;
    int ending_index;
    int values[STACK_SIZE - 1];
} queue;

void insert(queue* q, int val) {
    if (q->ending_index == STACK_SIZE - 1) {
        printf("Maximum queue size reached\n");
        return;
    }

    if(q->beginning_index == q->ending_index) {
        q->values[0] = val;
        q->ending_index++;
        return;
    }

    q->ending_index++;
    q->values[q->ending_index - 1] = val;
}

void read(queue* q) {
    printf("Beginning: %d - Ending: %d\n",q->values[q->beginning_index], q->values[q->ending_index - 1]);
}

void pop(queue* q) {
    if(q->beginning_index != q->ending_index) {
        int i = 0;

        while (i < q->ending_index) {
            q->values[i] = q->values[i + 1];
            i++;
        }
        
        q->values[q->ending_index] = 0;
        q->ending_index--;
    }
}

int main() {
    queue q = {.beginning_index = 0, .ending_index = 0};
    insert(&q, 10);
    read(&q);

    insert(&q, 11);
    insert(&q, 12);
    insert(&q, 13);
    insert(&q, 14);
    insert(&q, 15);
    read(&q);

    pop(&q);
    pop(&q);
    pop(&q);
    read(&q);
}
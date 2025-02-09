#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} linked_list;

node* create_node() {
    node* new_node = malloc(sizeof(node));

    if (new_node == NULL) {
        perror("Error allocating node");
        exit(EXIT_FAILURE);
    }

    return new_node;
}

void append(linked_list* list, int val) {
    node* new_node = create_node();

    new_node->next = NULL;
    new_node->value = val;

    if(list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        node* previous_tail = list->tail;
        previous_tail->next = new_node;
        list->tail = new_node;
    }
}

void prepend(linked_list* list, int val) {
    node* new_node = create_node();
    node* previous_head_node = list->head;
    new_node->value = val;

    if (previous_head_node == NULL) {
        list->head = new_node;
        list->tail = new_node;
        return;
    } else if (list->head == list->tail) {
        list->head->next = new_node;
        new_node->next = previous_head_node;
        previous_head_node->next = NULL;
        return;
    } else {
        list->head = new_node;
        new_node->next = previous_head_node;
    }
}

void print_linked_list(linked_list* list) {
    node* node = list->head;

    if (node == NULL) {
        printf("Error: empty list");
        return;
    }
    
    while (node != NULL) {
        printf("%d\n", node->value);
        node = node->next;
    }
    
}

int main() {
    linked_list list = {.head = NULL, .tail = NULL};
    linked_list* lin_list_ptr = &list;
    
    printf("Before prepend\n");
    append(lin_list_ptr, 5);
    append(lin_list_ptr, 15);
    append(lin_list_ptr, 15);
    append(lin_list_ptr, 15);
    append(lin_list_ptr, 25);
    print_linked_list(lin_list_ptr);
    printf("After prepend\n");
    prepend(lin_list_ptr, 10);
    prepend(lin_list_ptr, 11);
    prepend(lin_list_ptr, 12);
    prepend(lin_list_ptr, 13);
    append(lin_list_ptr, 99);
    print_linked_list(lin_list_ptr);
}
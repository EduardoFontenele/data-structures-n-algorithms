#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node;

struct linked_list{
    node* head;
    size_t size;
};

linked_list* list_create() {
    linked_list* list = malloc(sizeof(linked_list));
    if(!list) {
        fprintf(stderr, "Error allocating new list\n");
        return NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

bool list_destroy(linked_list* list) {
    if(!list) return true;
    
    node* current = list->head;

    while(current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }

    free(list);

    return true;
}

bool list_push(linked_list* list, int value) {
    if(!list) {
        fprintf(stderr, "No such list\n");
        return false;
    }

    node* new_node = malloc(sizeof(node));

    if(!new_node) {
        fprintf(stderr, "Error allocating node\n");
        return false;
    }

    new_node->value = value;
    new_node->next = NULL;

    if(list->head == NULL) {
        list->head = new_node;
    } else {
        node* current = list->head;
    
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }

    list->size++;
    return true;
}

bool list_pop(linked_list* list, int* value) {
    if(!list || !list->head) return false;

    node** head_ptr = &(list->head);
    node* to_delete = *head_ptr;
    *value = to_delete->value;
    *head_ptr = to_delete->next;
    free(to_delete);
    list->size--;
    return true;
}

size_t list_size(const linked_list* list) {
    return list->size;
}

bool list_peek(const linked_list* list, int* value) {
    if(!list) return false;

    if(list->head) {
        *value = list->head->value;
        return true;
    }

    return false;
}

void list_print(const linked_list* list) {
    if(!list || !list->head) return;
    
    node* current = list->head;


    printf("[\n");
    int iterator = 1;
    while(current) {
        if(iterator == list->size) {
            printf("\t{ Node:%d, value:%d }\n", iterator, current->value);
        } else {
            printf("\t{ Node:%d, value:%d },\n", iterator, current->value);
            iterator++;
        }
        current = current->next;
    }
    printf("]");
}

void list_clear(linked_list* list) {
    node* current = list->head;

    while(current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}

bool list_contains(const linked_list* list, int value) {
    if(!list) {
        fprintf(stderr, "Error: function called with NULL pointer\n");
        return false;
    };

    if(!list->head) return false;

    node* current = list->head;

    while(current) {
        if(current->value == value) return true;
        current = current->next;
    }

    return false;
}

bool list_remove_value(linked_list* list, int value) {
    if(!list || !list->head) return false;
   
    node** current_ptr = &(list->head);

    while(*current_ptr) {
        if((*current_ptr)->value == value) {
            node* to_delete = *current_ptr;
            *current_ptr = (*current_ptr)->next;
            free(to_delete);
            list->size--;
            return true;
        }

        current_ptr = &(*current_ptr)->next;
    }

    return false;
}
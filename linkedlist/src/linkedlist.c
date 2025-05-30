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
    if(list == NULL) {
        perror("Error while allocating memory for linked list");
        return NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

bool list_destroy(linked_list* list) {
    if(list == NULL) {
        return true;
    }

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
    if(list == NULL) {
        perror("No such list");
        return false;
    }

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) {
        perror("Failed while creating node");
        return false;
    }

    new_node->value = value;
    new_node->next = NULL;

    if(list->head == NULL) {
        list->head = new_node;
        list->size++;
        return true;
    }

    node* current = list->head;
    
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    list->size++;
    return true;
}

bool list_pop(linked_list* list, int* value) {
    if(list == NULL) {
        return false;
    }

    if(list->head == NULL) {
        return false;
    }

    if(list->head->next == NULL) {
        int head_value = list->head->value;
        free(list->head);
        list->head = NULL;
        *value = head_value;
        list->size--;
        return true;
    } else {
        node* new_head = list->head->next;
        node* old_head = list->head;
        list->head = new_head;
        int head_value = old_head->value;
        free(old_head);
        *value = head_value;
        list->size--;
        return true;
    }
}

size_t list_size(const linked_list* list) {
    return list->size;
}
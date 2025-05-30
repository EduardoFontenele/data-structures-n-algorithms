#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list linked_list;

linked_list* list_create();
bool list_destroy(linked_list*);
bool list_push(linked_list*, int);
bool list_pop(linked_list*, int*);
size_t list_size(const linked_list*);
bool list_peek(const linked_list*, int*);  // Vê sem remover
bool list_contains(const linked_list*, int);
bool list_remove_value(linked_list*, int);
void list_clear(linked_list*);
void list_print(const linked_list*);

#endif
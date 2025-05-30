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

#endif
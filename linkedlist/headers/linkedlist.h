#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list linked_list;

linked_list* list_create(void);
bool list_destroy(linked_list* list);
bool list_push(linked_list* list, int value);
bool list_pop(linked_list* list, int* value);
bool list_pop_back(linked_list* list, int* value);
size_t list_size(const linked_list* list);
bool list_peek(const linked_list* list, int* value);
bool list_peek_back(const linked_list* list, int* value);
void list_print(const linked_list* list);
void list_print_reverse(const linked_list* list);
void list_clear(linked_list* list);
bool list_contains(const linked_list* list, int value);
bool list_remove_value(linked_list* list, int value);

#endif
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
   int value;
   struct node* next;
   struct node* previous;
} node;

struct linked_list{
   node* head;
   node* tail;
   size_t size;
};

linked_list* list_create() {
   linked_list* list = malloc(sizeof(linked_list));
   if(!list) {
       fprintf(stderr, "Error allocating new list\n");
       return NULL;
   }

   list->head = NULL;
   list->tail = NULL;
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
   new_node->previous = NULL;

   if(list->head == NULL) {
       list->head = new_node;
       list->tail = new_node;
   } else {
       list->tail->next = new_node;
       new_node->previous = list->tail;
       list->tail = new_node;
   }

   list->size++;
   return true;
}

bool list_pop(linked_list* list, int* value) {
   if(!list || !list->head) return false;

   node* to_delete = list->head;
   *value = to_delete->value;
   
   list->head = to_delete->next;

   if(list->head) {
       list->head->previous = NULL;
   } else {
       list->tail = NULL;
   }
   
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
   if(!list) return;
   
   node* current = list->head;

   while(current != NULL) {
       node* next = current->next;
       free(current);
       current = next;
   }

   list->head = NULL;
   list->tail = NULL;
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
  
   node* current = list->head;

   while(current) {
       if(current->value == value) {
           if(current->previous) {
               current->previous->next = current->next;
           } else {
               list->head = current->next;
           }
           
           if(current->next) {
               current->next->previous = current->previous;
           } else {
               list->tail = current->previous;
           }
           
           free(current);
           list->size--;
           return true;
       }
       current = current->next;
   }

   return false;
}

bool list_pop_back(linked_list* list, int* value) {
   if(!list || !list->tail) return false;

   node* to_delete = list->tail;
   *value = to_delete->value;
   
   list->tail = to_delete->previous;
   if(list->tail) {
       list->tail->next = NULL;
   } else {
       list->head = NULL;
   }
   
   free(to_delete);
   list->size--;
   return true;
}

bool list_peek_back(const linked_list* list, int* value) {
   if(!list || !list->tail) return false;

   *value = list->tail->value;
   return true;
}

void list_print_reverse(const linked_list* list) {
   if(!list || !list->tail) return;
   
   node* current = list->tail;

   printf("[\n");
   int iterator = list->size;
   while(current) {
       if(iterator == 1) {
           printf("\t{ Node:%d, value:%d }\n", iterator, current->value);
       } else {
           printf("\t{ Node:%d, value:%d },\n", iterator, current->value);
           iterator--;
       }
       current = current->previous;
   }
   printf("]");
}
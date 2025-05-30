#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include <stdbool.h>

int main() {
    linked_list* list = list_create();
    bool created = true;

    int i = 1;
    while (created && i < 11) {
        created = list_push(list, i * 3);
        i++;
    }
    
    list_print(list);
}
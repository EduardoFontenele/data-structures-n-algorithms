#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char** argv) {
linked_list* lista = list_create();
   if (!lista) {
       fprintf(stderr, "Erro ao criar lista\n");
       return 1;
   }

   list_push(lista, 47);
   list_push(lista, 12);
   list_push(lista, 89);
   list_push(lista, 3);
   list_push(lista, 76);
   list_push(lista, 34);
   list_push(lista, 91);
   list_push(lista, 18);
   list_push(lista, 65);
   list_push(lista, 29);
   
   list_sort(lista);
   
   list_destroy(lista);
   return 0;
}
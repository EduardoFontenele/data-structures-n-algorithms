#include "utils.h"
#include <stdio.h>

void print_arr(int arr[], size_t size) {
    printf("[ ");
    for(int i = 0; i < size; i++) {
        if (i == size - 1)
        {
            printf("%d ]\n", arr[i]);
            return;
        }
        
        printf("%d, ", arr[i]);
    }
    printf("]\n");
} 
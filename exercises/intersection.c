#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

int* find_intersection(int* arr1, int* arr2) {
    if (arr1 == NULL || arr2 == NULL)
        exit(EXIT_FAILURE);

    int* response = calloc(ARRAY_SIZE, sizeof(int));

    int i, j;

    for(i = 0; i < ARRAY_SIZE; i++) {
        j = i;
        while(j < ARRAY_SIZE) {
            if (arr1[i] == arr2[j]) {
                *(response + i) = arr1[j];
                j++;
                break;
            }
            j++;
        }
    }
    
    return response;
}

int main() {
    int* arr1= (int[]){3, 12, 9, 4, 2};
    int* arr2= (int[]){25, 11, 3, 74, 12};
    int* response = find_intersection(arr1, arr2);

    int i = 0;
    while (i < ARRAY_SIZE) {
        printf("%d\n", *(response + i));
        i++;
    }

    free(response);
}
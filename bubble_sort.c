#include <stdio.h>

void bubble_sort(int[], size_t);

void print_array(int arr[], size_t arr_size) {
    for(int i = 0; i < arr_size; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[5] = {37, 82, 15, 94, 56};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    printf("------BEFORE SORTING------\n");
    print_array(arr, size);
    bubble_sort(arr, size);
    printf("------AFTER SORTING------\n");
    print_array(arr, size);
}

void bubble_sort(int array[], size_t size) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++) {
            if (j == size - 1)
                break;

            int val1 = array[j];
            int val2 = array[j + 1];
           
            if (val1 > val2) {
                array[j+1] = val1;
                array[j] = val2;
            } 
        }
}
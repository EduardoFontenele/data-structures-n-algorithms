#include "utils.h"

void sort(int arr[], size_t size) {
    int* current_lowest_value = arr;

    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if (arr[j] < *current_lowest_value) {
                int temp = arr[j];
                int temp2 = *current_lowest_value;

                *current_lowest_value = temp;
                arr[j] = temp2;
            }
        }

        current_lowest_value++;
    }
}

int main() {
    int arr[] = {19, 9, 23, 11};
    size_t size = sizeof(arr)/sizeof(int);
    print_arr(arr, size);
    sort(arr, size);
    print_arr(arr, size);
}
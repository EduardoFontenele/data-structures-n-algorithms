#include <stdio.h>
#include <stdbool.h>

void quicksort(int[], int, int);
void quicksort_helper(int[], int);

int main() {
    int* arr = (int[]){ 0, 5, 2, 1, 6, 3 };
    size_t arr_size = 6;
    for(int i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
    }

    printf("\n");

    quicksort_helper(arr, arr_size);
    for(int i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
    }

    printf("\n");
}

void quicksort(int arr[], int left_ptr, int right_ptr) {
    if(left_ptr >= right_ptr) return;

    int pivot_index = right_ptr;
    int pivot = arr[pivot_index];
    right_ptr--;

    while(true) {
        while(arr[left_ptr] < pivot) {
            left_ptr++;
        }

        while(arr[right_ptr] > pivot) {
            right_ptr--;
        }

        if(left_ptr >= right_ptr) {
            break;
        } else {
            int left_val = arr[left_ptr];
            int right_val = arr[right_ptr];
            arr[left_ptr] = right_val;
            arr[right_ptr] = left_val;
            left_ptr++;
        }
    }

    arr[pivot_index] = arr[left_ptr];
    arr[left_ptr] = pivot;

    quicksort(arr, 0, left_ptr - 1);
    quicksort(arr, left_ptr + 1, pivot_index);
}

void quicksort_helper(int arr[], int arr_size) {
    quicksort(arr, 0, arr_size - 1);
}
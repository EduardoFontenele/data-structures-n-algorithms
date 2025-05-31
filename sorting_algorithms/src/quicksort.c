#include <stdio.h>
#include <stdbool.h>
#include "quicksort.h"

void sort(int arr[], int left_ptr, int right_ptr) {
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

    sort(arr, 0, left_ptr - 1);
    sort(arr, left_ptr + 1, pivot_index);
}

void quicksort(int arr[], size_t arr_size) {
    sort(arr, 0, arr_size - 1);
}
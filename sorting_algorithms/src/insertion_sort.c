#include "utils.h"

void sort(int array[], size_t size) {
    for(int i = 1; i < size; i++) {
        int temp = array[i];

        for(int j = i - 1; j >= 0; j--) {
            if (array[j] > array[j+1]) {
                int temp2 = array[j];
                array[j] = temp;
                array[j + 1] = temp2;
            }  else {
                break;
            }
        }
    }
}

int main() {
    int arr[] = {4,2,7,1,3};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    printf("Antes: ");
    print_arr(arr, size);

    sort(arr, size);

    printf("Depois: ");
    print_arr(arr, size);

    int arr2[] = {43, 13, 95, 9, 44, 29, 75, 32, 88, 15};
    size_t size2 = sizeof(arr2)/sizeof(arr[0]);

    printf("Antes: ");
    print_arr(arr2, size2);

    sort(arr2, size2);

    printf("Depois: ");
    print_arr(arr2, size2);
}

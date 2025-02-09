#include <stdio.h>

#define ARRAY_SIZE 11
#define true 1
#define false 0
#define PRINT_BOOL_RESULT(boolean) (boolean == 1 ? printf("true\n") : printf("false\n"))

typedef int boolean;

boolean linear_search(int* array, int searched_value, int arr_size) {
    int i = 0;
    while(i < arr_size) {
        if (searched_value == array[i])
            return true;
        i++;
    }
    return false;
}

int main() {
    int arr[] = {78, 181, 197, 255, 293, 337, 430, 589, 632, 721, 924};
    int some_number = 337;
    boolean number_is_present = linear_search(&arr[0], 721, (int) sizeof(arr)/sizeof(arr[0]));

    PRINT_BOOL_RESULT(number_is_present);
}



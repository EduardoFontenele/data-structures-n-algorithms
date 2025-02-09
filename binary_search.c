#include <stdio.h>

#define ARRAY_SIZE 11
#define true 1
#define false 0
#define PRINT_BOOL_RESULT(boolean) (boolean == 1 ? printf("true\n") : printf("false\n"))

typedef int boolean;

boolean binary_search(int* arr, int srch_value, int arr_size) {
   int lower_bond = 0;
   int upper_bond = arr_size - 1;
   
   while(lower_bond <= upper_bond) {
      int mid_point = (lower_bond + upper_bond) / 2;
      int value_at_midpoint = arr[mid_point];

      if (value_at_midpoint == srch_value) {
         return true;
      } else if (value_at_midpoint > srch_value) {
         upper_bond = mid_point - 1;
      } else if(value_at_midpoint < srch_value) {
         lower_bond = mid_point + 1;
      }   
   };

   return false;
}

int main() {
   int arr[ARRAY_SIZE] = {78, 181, 197, 255, 293, 337, 430, 589, 632, 721, 924};
   int some_number = 78;
   boolean is_present = binary_search(arr, some_number, (int) sizeof(arr)/sizeof(arr[0]));
   PRINT_BOOL_RESULT(is_present);
}


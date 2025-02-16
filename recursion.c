#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INITIAL_LEVEL 0

void countdown(int initial_val) {
    printf("%d\n", initial_val);
    if (initial_val > 0)
        countdown(initial_val - 1);
}

int fatorial(int val) {
    while (val > 1) 
        return val * fatorial(val - 1);
}

void read_dirs(const char* dirname, int current_level) {
    if(dirname == NULL) {
        perror("dirname is null for some reason and God knows why, but I dont. Exiting...");
        exit(EXIT_FAILURE);
    }
    DIR* dir = opendir(dirname);
    struct dirent *entry;

    char next_dir[200];

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
        int is_folder = strchr(entry->d_name, '.') == NULL ? TRUE : FALSE;
        if(is_folder == TRUE) {
            strcpy(next_dir, dirname);
            strcat(next_dir, "/");
            strcat(next_dir, entry->d_name);
            read_dirs(next_dir, current_level + 1);
        }
        
    }

    closedir(dir);
}

int triangular_numbers(int number_position) {
    int i = 1;
    int prev_val = 0;

    while(i < number_position + 1) {
        prev_val = i + prev_val;
        i++;
    }

    return prev_val;
}

int triangular_numbers_recursive(int number_position) {
    if (number_position == 1) return 1;
    if(number_position > 1) return number_position + triangular_numbers(number_position - 1);
}

int main() {
    const char *dirname = "."; 
    read_dirs(dirname, INITIAL_LEVEL);
    int result = triangular_numbers_recursive(7);
    printf("triangular numbers recursive (7): %d\n", result);
    result = triangular_numbers(7);
    printf("triangular numbers non-recursive (7): %d\n", result);
}
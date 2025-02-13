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

    char next_dir[123];
    char level[100];
    for(int i = 0; i <= current_level; i++) {
        strcat(level, "-");
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("|%s %s\n",level, entry->d_name);
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

int main() {
    const char *dirname = "."; 
    read_dirs(dirname, INITIAL_LEVEL);
}
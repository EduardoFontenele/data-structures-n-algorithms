#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 8
#define EQUAL_STR 0
#define FIRST_STR_IS_SMALLER -1
#define FIRST_STR_IS_BIGGER 1

typedef struct node {
    char* key;
    char* value;
    struct node* next;
} node;


typedef struct {
    node** map;
} HashMap;

unsigned int hash(char* key) {
    unsigned int hashValue = 5381;
    int c;

    while ((c = *key++)) {
        hashValue = ((hashValue << 5) + hashValue) + c;  // hash = hash * 33 + c
    }
    
    return hashValue % MAP_SIZE;
}

HashMap* create_map() {
    HashMap* hashMap = malloc(sizeof(HashMap));
    hashMap->map = calloc(MAP_SIZE, sizeof(node*));
    return hashMap;
}

void insert(HashMap* hashMap, char* key, char* value) {
    unsigned int index = hash(key);
    node* newNode = malloc(sizeof(node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;

    node* current = hashMap->map[index];
    if (current == NULL) {
        hashMap->map[index] = newNode;
    } else {
        newNode->next = current;
        hashMap->map[index] = newNode;
    }
}

char* search(HashMap* hashMap, char* key) {
    unsigned int index = hash(key);
    node* current = hashMap->map[index];

    while(current != NULL) {
        if(strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void delete(HashMap* hashMap, char* key) {
    unsigned int index = hash(key);
    node* current = hashMap->map[index];
    node* previous = NULL;

    if (current == NULL) {
        return;
    }

    while (current != NULL) {
        int comparisonResult = strcmp(current->key, key);

        if (comparisonResult == EQUAL_STR) {
            if (previous == NULL) {
                hashMap->map[index] = current->next;
            } else {
                previous->next = current->next;
            }

            free(current->key);
            free(current->value);
            free(current);
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void free_map(HashMap* hashMap) {
    for (int i = 0; i < MAP_SIZE; i++) {
        node* current = hashMap->map[i];
        while (current != NULL) {
            node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(hashMap->map);
    free(hashMap);
}

int main() {
    HashMap* hashMap = create_map();

    insert(hashMap, "apple", "fruit");
    insert(hashMap, "banana", "fruit");
    insert(hashMap, "carrot", "vegetable");

    printf("apple: %s\n", search(hashMap, "apple"));
    printf("banana: %s\n", search(hashMap, "banana"));
    printf("carrot: %s\n", search(hashMap, "carrot"));  

    delete(hashMap, "banana");

    printf("banana após remoção: %s\n", search(hashMap, "banana"));  // Deve retornar NULL

    free_map(hashMap);
}

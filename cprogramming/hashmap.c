#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Node structure for linked list in case of collisions
typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

// Hash map structure
typedef struct {
    Node *table[TABLE_SIZE];
} HashMap;

// Hash function
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    }
    return hash % TABLE_SIZE;
}

// Create a new node
Node *createNode(const char *key, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Initialize a hash map
void initHashMap(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
}

// Insert a key-value pair into the hash map

void insert(HashMap *map, const char *key, int value) {
    unsigned int index = hash(key);
    Node *newNode = createNode(key, value);

    // Check for collision and handle with separate chaining
    if (map->table[index] == NULL) {
        map->table[index] = newNode;
    } else {
        Node *current = map->table[index];
        Node *prev = NULL;

        // Search for the key in the linked list
        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                // If key already exists, replace the existing node
                if (prev == NULL) {
                    // If the existing node is the first in the list
                    newNode->next = current->next;
                    map->table[index] = newNode;
                } else {
                    // If the existing node is not the first in the list
                    newNode->next = current->next;
                    prev->next = newNode;
                }

                // Free the memory of the existing node
                free(current->key);
                free(current);

                return; // Key replaced, exit the function
            }

            prev = current;
            current = current->next;
        }

        // Key not found, add the new node to the end of the list
        prev->next = newNode;
    }
}


// Search for a key in the hash map and return the corresponding value
int search(HashMap *map, const char *key) {
    unsigned int index = hash(key);
    Node *current = map->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Cleanup and free memory used by the hash map
void cleanupHashMap(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = map->table[i];
        while (current != NULL) {
            Node *next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
    }
}

int main() {
    HashMap myMap;
    initHashMap(&myMap);

    // Insert key-value pairs
    insert(&myMap, "John", 25);
    insert(&myMap, "Alice", 30);
    insert(&myMap, "Bob", 22);
    insert(&myMap, "Bob", 95);
    // Search for values
    printf("John's age: %d\n", search(&myMap, "John"));
    printf("Alice's age: %d\n", search(&myMap, "Alice"));
    printf("Bob's age: %d\n", search(&myMap, "Bob"));
    printf("Dave's age: %d\n", search(&myMap, "Dave"));  // Not found

    // Cleanup
    cleanupHashMap(&myMap);

    return 0;
}
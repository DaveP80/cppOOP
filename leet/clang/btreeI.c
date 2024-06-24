#include <stdio.h>
#include <stdlib.h>

// Minimum degree (defines the range for number of keys)
#define T 3

// B-tree node structure
struct BTreeNode {
    int *keys; // An array of keys
    int t; // Minimum degree (defines the range for number of keys)
    struct BTreeNode **C; // An array of child pointers
    int n; // Current number of keys
    int leaf; // Is true when node is leaf. Otherwise false
};

// Function to create a new B-tree node
struct BTreeNode *createNode(int t, int leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = (int *)malloc((2 * t - 1) * sizeof(int));
    newNode->C = (struct BTreeNode **)malloc((2 * t) * sizeof(struct BTreeNode *));
    newNode->n = 0;
    return newNode;
}

// Binary search function to find the index of the first key greater than or equal to k
int findKey(struct BTreeNode *node, int k) {
    int low = 0;
    int high = node->n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (node->keys[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

// Example usage
int main() {
    // Create a sample node
    struct BTreeNode *node = createNode(T, 1);
    node->keys[0] = 5;
    node->keys[1] = 8;
    node->keys[2] = 11;
    node->keys[3] = 12;
    node->n = 4;

    // Find the index for the key 9
    int index = findKey(node, 9);
    printf("Index to insert or search: %d\n", index); // Output: 2

    // Clean up
    free(node->keys);
    free(node->C);
    free(node);

    return 0;
}
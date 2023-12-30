/**
 * LeetCode No. 1557
 * Minimum number of vertices to reach all nodes.
 * Runtime 291 ms
 * **/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {

    bool* visited = calloc(n, sizeof(bool));

    for (int i = 0; i < edgesSize; i++) {
        visited[edges[i][1]] = true;
    }

    int* ans = malloc(n * sizeof(int));
    int ansIdx = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans[ansIdx++] = i;
        }
    }

    *returnSize = ansIdx;

    free(visited);
    return ans;
}
int main() {
    // Example edges array
    int edgeArr[][2] = {{0, 1}, {0, 2}, {2, 5}, {3, 4}};
    int edgesSize = 4;
    int edgesColSize[] = {2, 2, 2, 2};

    // Number of vertices
    int n = 6;

    // Call the function
    int returnSize;
    int* result = findSmallestSetOfVertices(n, (int**)edgeArr, edgesSize, edgesColSize, &returnSize);

    // Print the result
    printf("Smallest Set of Vertices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}
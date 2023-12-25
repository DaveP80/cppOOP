// Leetcode No. 1496
#include <stdio.h>
#include <stdbool.h>
bool isPathCrossing(char* path) {
    int stor[strlen(path) + 1][2];
    stor[0][0] = 0;
    stor[0][1] = 0;
    int idx = 1;

    int length = sizeof(stor) / sizeof(stor[0]);

    for (int i = 0; i < strlen(path); i++) {
        int temp[2];

        if (path[i] == 'N') {
            temp[0] = stor[idx-1][0];
            temp[1] = stor[idx-1][1] + 1;
        }
        if (path[i] == 'S') {
            temp[0] = stor[idx-1][0];
            temp[1] = stor[idx-1][1] - 1;
        }
        if (path[i] == 'E') {
            temp[0] = stor[idx-1][0] + 1;
            temp[1] = stor[idx-1][1];
        }
        if (path[i] == 'W') {
            temp[0] = stor[idx-1][0] - 1;
            temp[1] = stor[idx-1][1];
        }

        for (int z = 0; z < idx; z++) {
            if (temp[0] == stor[z][0] && temp[1] == stor[z][1]) {
                return true;
            }
        }

        stor[idx][0] = temp[0];
        stor[idx][1] = temp[1];
        idx++;
    }

    return false;
}
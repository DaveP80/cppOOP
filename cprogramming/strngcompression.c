//LeetCode No. 1531
//Partial Solution
#include <stdio.h>
#include <string.h>

struct KeyValuePair {
    char key[6];
    int value;
};

struct KeyValuePair stor[110];
int l = 101;
char *gs;
int idx = 0;

int count(int i, int k, char prev, int prev_count);

int getLengthOfOptimalCompression(char* s, int k) {
    l = strlen(s);
    gs = s;
    return count(0, k, '\0', 0);
}

int count(int i, int k, char prev, int prev_count) {
    int res = 0;

    char str1[6]; // Adjust the size based on the expected number length
    sprintf(str1, "%d", i);

    char str2[6]; // Adjust the size based on the expected number length
    sprintf(str2, "%d", k);

    char str4[6]; // Adjust the size based on the expected number length
    sprintf(str4, "%d", prev_count);

    char str3[2] = {prev, '\0'}; // Ensure size is sufficient for a single character plus null terminator

    size_t totalLength = strlen(str1) + strlen(str2) + strlen(str3) + strlen(str4);
    char concatenatedString[totalLength + 1]; // +1 for the null terminator
    strcpy(concatenatedString, str1);
    strcat(concatenatedString, str2);
    strncat(concatenatedString, str3, 1); // Use strncat to limit the number of characters
    strcat(concatenatedString, str4);

    for (int z = 0; z < 110; z++) {
        if (stor[z].key[0] != '\0' && strncmp(concatenatedString, stor[z].key, totalLength) == 0) {
            return stor[z].value;
        }
    }

    if (k < 0) {
        return l + 1;
    }

    if (i == l) {
        return 0;
    }

    if (gs[i] == prev) {
        int inc = 0;
        if (prev_count == 1 || prev_count == 99 || prev_count == 9) {
            inc = 1;
        }
        res = inc + count(i + 1, k, prev, prev_count + 1);
    } else {
        int a = count(i + 1, k - 1, prev, prev_count);
        int b = 1 + count(i + 1, k, gs[i], 1);
        res = a > b ? b : a;
    }

    char str1b[6]; // Adjust the size based on the expected number length
    sprintf(str1b, "%d", i);

    char str2b[6]; // Adjust the size based on the expected number length
    sprintf(str2b, "%d", k);

    char str4b[6]; // Adjust the size based on the expected number length
    sprintf(str4b, "%d", prev_count);

    char str3b[2] = {prev, '\0'}; // Ensure size is sufficient for a single character plus null terminator

    size_t totalLengthb = strlen(str1b) + strlen(str2b) + strlen(str3b) + strlen(str4b);
    char concatenatedStringb[totalLengthb + 1]; // +1 for the null terminator
    strcpy(concatenatedStringb, str1b);
    strcat(concatenatedStringb, str2b);
    strncat(concatenatedStringb, str3b, 1); // Use strncat to limit the number of characters
    strcat(concatenatedStringb, str4b);

    strcpy(stor[idx].key, concatenatedStringb);
    stor[idx].value = res;
    idx++;

    return res;
}
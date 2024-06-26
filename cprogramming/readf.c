#include <stdio.h>
//Program to read file in same level as project directory

int main() {
    FILE *file;
    char line[100];  // Assuming each line has at most 100 characters

    // Open the file in read mode
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File 'input.txt' not found.\n");
        return 1;
    }

    // Read each line and print its content
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);
    return 0;
}

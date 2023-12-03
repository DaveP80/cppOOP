#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char* reverseString(const char* input) {
    size_t length = strlen(input);
    
    // Allocate memory for the reversed string (including null terminator)
    char* reversed = (char*)malloc((length + 1) * sizeof(char));

    if (reversed == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy characters in reverse order
    for (size_t i = 0; i < length; i++) {
        reversed[i] = input[length - i - 1];
    }

    // Add null terminator
    reversed[length] = '\0';

    return reversed;
}

int main() {
    // Get user input
    printf("Enter a string: ");
    char input[100];  // Assuming a maximum input length of 99 characters
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input (if present)
    size_t inputLength = strlen(input);
    if (inputLength > 0 && input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
    }

    // Reverse the string
    char* reversedString = reverseString(input);

    // Print the reversed string
    printf("Reversed string: %s\n", reversedString);

    // Free dynamically allocated memory
    free(reversedString);

    return 0;
}
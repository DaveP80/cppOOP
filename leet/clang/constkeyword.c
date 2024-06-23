#include <stdio.h>
//the way to have read only properties in C, constant variables.

typedef struct {
    int writable;
    const int readonly;
} MyStruct;

int main() {
    MyStruct s = {10, 20};

    printf("writable: %d\n", s.writable);
    printf("readonly: %d\n", s.readonly);

    s.writable = 30; // Allowed
    // s.readonly = 40; // Compilation error: read-only variable is not assignable

    printf("writable: %d\n", s.writable);
    printf("readonly: %d\n", s.readonly);

    return 0;
}
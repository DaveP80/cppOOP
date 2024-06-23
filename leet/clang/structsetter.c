#include <stdio.h>

typedef struct {
    int writable;
    int readonly;
} MyStruct;

void initMyStruct(MyStruct *s, int writable, int readonly) {
    s->writable = writable;
    s->readonly = readonly;
}

int getReadonly(const MyStruct *s) {
    return s->readonly;
}

void setWritable(MyStruct *s, int value) {
    s->writable = value;
}

int main() {
    MyStruct s;
    initMyStruct(&s, 10, 20);

    printf("writable: %d\n", s.writable);
    printf("readonly: %d\n", getReadonly(&s));

    setWritable(&s, 30);
    // setReadonly(&s, 40); // No such function, readonly property cannot be modified

    printf("writable: %d\n", s.writable);
    printf("readonly: %d\n", getReadonly(&s));

    return 0;
}
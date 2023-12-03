#include <stdio.h>

struct Point {
    float x;
    float y;
};

struct MyStruct {
    char message[6];
    struct Point location;
};

int main() {
    struct MyStruct mystruct = { "hello", {44.22, 55.22}};
    printf("point 0 %f\npoint 1 %f\n%s\n", mystruct.location.x, mystruct.location.y, mystruct.message);

    return 0;
}
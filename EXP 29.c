#include <stdio.h>

int main() {
    printf("Process 1 entering Critical Section\n");
    printf("Process 1 leaving Critical Section\n");

    printf("Process 2 entering Critical Section\n");
    printf("Process 2 leaving Critical Section\n");

    return 0;
}

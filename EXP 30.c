#include <stdio.h>
#include <pthread.h>

void* display(void* arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, display, NULL);
    pthread_join(t, NULL);

    printf("Thread completed\n");
    return 0;
}

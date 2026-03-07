#include <stdio.h>
#include <pthread.h>
// Thread Function 1
void* task1(void* arg) {
    printf("\n+----------------+---------------------------+\n");
    printf("| %-14s | %-25s |\n", "Thread", "Task");
    printf("+----------------+---------------------------+\n");
    printf("| %-14s | %-25s |\n", "Thread 1", "Printing Numbers");
    printf("+----------------+---------------------------+\n");
    return NULL;
}
// Thread Function 2
void* task2(void* arg) {
    printf("\n+----------------+---------------------------+\n");
    printf("| %-14s | %-25s |\n", "Thread", "Task");
    printf("+----------------+---------------------------+\n");
    printf("| %-14s | %-25s |\n", "Thread 2", "Printing Alphabets");
    printf("+----------------+---------------------------+\n");
    return NULL;
}
int main() {
    pthread_t t1, t2;
    // Create Threads
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    // Wait for Threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    printf("\n+---------------+----------------+\n");
    printf("| %-13s | %-14s |\n", "Philosopher", "State");
    printf("+---------------+----------------+\n");
    printf("| %-13d | %-14s |\n", id, "Thinking");
    printf("+---------------+----------------+\n");

    // Pick left and right chopstick
    pthread_mutex_lock(&chopstick[id]);
    pthread_mutex_lock(&chopstick[(id + 1) % N]);

    printf("| %-13d | %-14s |\n", id, "Eating");
    printf("+---------------+----------------+\n");

    sleep(1);

    // Release chopsticks
    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[(id + 1) % N]);

    printf("| %-13d | %-14s |\n", id, "Finished");
    printf("+---------------+----------------+\n");

    return NULL;
}

int main() {
    pthread_t thread[N];
    int phil[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for (int i = 0; i < N; i++) {
        phil[i] = i + 1;
        pthread_create(&thread[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    return 0;
}

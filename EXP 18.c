#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t full, empty;

void* producer(void* arg){
    printf("Produced item\n");
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg){
    sem_wait(&full);
    printf("Consumed item\n");
    return NULL;
}

int main(){
    pthread_t p,c;
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);
    return 0;
}

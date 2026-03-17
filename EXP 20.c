#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
int readcount=0;

void* reader(void* arg){
    readcount++;
    if(readcount==1)
        sem_wait(&wrt);
    printf("Reader reading\n");
    readcount--;
    if(readcount==0)
        sem_post(&wrt);
    return NULL;
}

void* writer(void* arg){
    sem_wait(&wrt);
    printf("Writer writing\n");
    sem_post(&wrt);
    return NULL;
}

int main(){
    pthread_t r,w;
    sem_init(&wrt,0,1);

    pthread_create(&r,NULL,reader,NULL);
    pthread_create(&w,NULL,writer,NULL);

    pthread_join(r,NULL);
    pthread_join(w,NULL);
    return 0;
}

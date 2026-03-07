#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    key_t key = 1234;
    int shmid;
    char *str;
    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    // Attach shared memory
    str = (char*) shmat(shmid, NULL, 0);
    if (fork() == 0) {
        // Child Process writes to shared memory
        strcpy(str, "Hello from Child Process");
        printf("\n+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Process", "Operation", "Message Written");
        printf("+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Child Process", "Write", str);
        printf("+----------------+------------+------------------------------+\n");
    } 
    else {
        wait(NULL);   // Parent waits for child
        printf("\n+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Process", "Operation", "Message Read");
        printf("+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Parent Process", "Read", str);
        printf("+----------------+------------+------------------------------+\n");
        // Detach and remove shared memory
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}

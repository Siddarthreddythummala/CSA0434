#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};
int main() {
    key_t key = 1234;
    int msgid;
    struct msg_buffer message;
    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (fork() == 0) {
        // Child Process - Receive message
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("\n+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Process", "Operation", "Message");
        printf("+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Child Process", "Receive", message.msg_text);
        printf("+----------------+------------+------------------------------+\n");
    }
    else {
        // Parent Process - Send message
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Parent Process");
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        wait(NULL);
        printf("\n+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Process", "Operation", "Message");
        printf("+----------------+------------+------------------------------+\n");
        printf("| %-14s | %-10s | %-28s |\n", "Parent Process", "Send", message.msg_text);
        printf("+----------------+------------+------------------------------+\n");
        // Delete message queue
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}

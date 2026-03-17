#include <stdio.h>

int main() {
    int users, files, i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 1; i <= users; i++) {
        printf("Enter number of files for User %d: ", i);
        scanf("%d", &files);
        for(j = 1; j <= files; j++)
            printf("User %d -> File %d created\n", i, j);
    }
    return 0;
}

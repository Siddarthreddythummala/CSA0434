#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
    char files[MAX][20];
    int count = 0, choice;
    char fname[20];

    while(1) {
        printf("\n1.Create  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: // Create
                if(count >= MAX) {
                    printf("\nDirectory Full!\n");
                    break;
                }
                printf("Enter file name: ");
                scanf("%s", fname);
                strcpy(files[count], fname);
                count++;
                printf("\n+----------------+\n");
                printf("| %-14s |\n", "File Created");
                printf("+----------------+\n");
                printf("| %-14s |\n", fname);
                printf("+----------------+\n");
                break;

            case 2: // Delete
                printf("Enter file name to delete: ");
                scanf("%s", fname);
                for(int i = 0; i < count; i++) {
                    if(strcmp(files[i], fname) == 0) {
                        for(int j = i; j < count-1; j++)
                            strcpy(files[j], files[j+1]);
                        count--;
                        printf("\n+----------------+\n");
                        printf("| %-14s |\n", "File Deleted");
                        printf("+----------------+\n");
                        printf("| %-14s |\n", fname);
                        printf("+----------------+\n");
                        break;
                    }
                }
                break;

            case 3: // Display
                printf("\n+-----------+----------------+\n");
                printf("| %-9s | %-14s |\n", "File No", "File Name");
                printf("+-----------+----------------+\n");
                for(int i = 0; i < count; i++)
                    printf("| %-9d | %-14s |\n", i+1, files[i]);
                printf("+-----------+----------------+\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

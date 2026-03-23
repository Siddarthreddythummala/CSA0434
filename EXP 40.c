#include<stdio.h>

int main(){
    char u[3], g[3], o[3];

    printf("Enter Owner permissions (rwx): ");
    scanf("%s",u);
    printf("Enter Group permissions (rwx): ");
    scanf("%s",g);
    printf("Enter Others permissions (rwx): ");
    scanf("%s",o);

    printf("\nUser Type\tPermissions\n");
    printf("Owner\t\t%s\n",u);
    printf("Group\t\t%s\n",g);
    printf("Others\t\t%s\n",o);

    return 0;
}

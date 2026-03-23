#include<stdio.h>

int main(){
    int n,i,index;

    printf("Enter index block: ");
    scanf("%d",&index);

    printf("Enter number of blocks: ");
    scanf("%d",&n);

    int b[n];
    printf("Enter block numbers:\n");
    for(i=0;i<n;i++) scanf("%d",&b[i]);

    printf("\nIndexBlock\tFileBlock\n");
    for(i=0;i<n;i++)
        printf("%d\t\t%d\n",index,b[i]);

    return 0;
}

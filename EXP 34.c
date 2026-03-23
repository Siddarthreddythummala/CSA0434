#include<stdio.h>

int main() {
    int n,i,start;
    
    printf("Enter number of records: ");
    scanf("%d",&n);
    
    printf("Enter starting block: ");
    scanf("%d",&start);

    printf("\nRecord\tBlock\n");
    
    for(i=0;i<n;i++)
        printf("%d\t%d\n",i+1,start+i);

    return 0;
}

#include<stdio.h>

int main(){
    int n,i;

    printf("Enter number of blocks: ");
    scanf("%d",&n);

    int b[n];
    printf("Enter block numbers:\n");
    for(i=0;i<n;i++) scanf("%d",&b[i]);

    printf("\nBlock\tNext\n");
    for(i=0;i<n;i++){
        if(i==n-1)
            printf("%d\tNULL\n",b[i]);
        else
            printf("%d\t%d\n",b[i],b[i+1]);
    }

    return 0;
}

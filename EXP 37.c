#include<stdio.h>

int main(){
    int n,i,head,total=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    int req[n];
    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("\nRequest\tHead Move\n");

    for(i=0;i<n;i++){
        int move = abs(req[i]-head);
        printf("%d\t%d\n",req[i],move);
        total += move;
        head = req[i];
    }

    printf("Total Seek Time = %d",total);
}

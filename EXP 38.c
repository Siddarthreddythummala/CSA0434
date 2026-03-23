#include<stdio.h>

int main(){
    int req[]={98,183,37,122,14,124,65,67};
    int n=8, head=53, i;

    printf("Request\tHead Move\n");

    for(i=0;i<n;i++){
        int move = abs(req[i]-head);
        printf("%d\t%d\n",req[i],move);
        head=req[i];
    }

    printf("SCAN completed");
}

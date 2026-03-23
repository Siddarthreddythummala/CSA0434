#include<stdio.h>
#include<stdlib.h>

int main(){
    int req[]={98,183,37,122,14}, head=53, i, move, total=0;

    printf("Request\tHeadMove\n");

    for(i=0;i<5;i++){
        move=abs(req[i]-head);
        printf("%d\t%d\n",req[i],move);
        total+=move;
        head=req[i];
    }

    printf("Total Seek = %d",total);
}

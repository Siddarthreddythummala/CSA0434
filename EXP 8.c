#include <stdio.h>

int main() {
    int n, bt[10], rt[10], tq;
    int time=0, remain;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    remain=n;

    while(remain!=0){
        for(int i=0;i<n;i++){
            if(rt[i]>0){
                if(rt[i]<=tq){
                    time+=rt[i];
                    rt[i]=0;
                    remain--;
                }
                else{
                    rt[i]-=tq;
                    time+=tq;
                }
            }
        }
    }

    printf("Round Robin Scheduling Completed\n");
    return 0;
}

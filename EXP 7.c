#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], done[10]={0};
    int completed=0, time=0, min, shortest;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Burst time P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    while(completed<n){
        min=9999;
        for(int i=0;i<n;i++){
            if(!done[i] && bt[i]<min){
                min=bt[i];
                shortest=i;
            }
        }

        wt[shortest]=time;
        time+=bt[shortest];
        tat[shortest]=wt[shortest]+bt[shortest];
        done[shortest]=1;
        completed++;
    }

    printf("\nBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n",bt[i],wt[i],tat[i]);

    return 0;
}

#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i] = -1;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

    printf("\nFIRST FIT\n");
    printf("+-----------+--------------+-------------+\n");
    printf("| %-9s | %-12s | %-11s |\n","Process","Size","Block No");
    printf("+-----------+--------------+-------------+\n");
    for(int i=0;i<n;i++)
        printf("| %-9d | %-12d | %-11d |\n",i+1,processSize[i],
               allocation[i] != -1 ? allocation[i]+1 : 0);
    printf("+-----------+--------------+-------------+\n");
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i] = -1;

    for(int i=0;i<n;i++){
        int best = -1;
        for(int j=0;j<m;j++)
            if(blockSize[j] >= processSize[i])
                if(best == -1 || blockSize[j] < blockSize[best])
                    best = j;

        if(best != -1){
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("+-----------+--------------+-------------+\n");
    printf("| %-9s | %-12s | %-11s |\n","Process","Size","Block No");
    printf("+-----------+--------------+-------------+\n");
    for(int i=0;i<n;i++)
        printf("| %-9d | %-12d | %-11d |\n",i+1,processSize[i],
               allocation[i] != -1 ? allocation[i]+1 : 0);
    printf("+-----------+--------------+-------------+\n");
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i] = -1;

    for(int i=0;i<n;i++){
        int worst = -1;
        for(int j=0;j<m;j++)
            if(blockSize[j] >= processSize[i])
                if(worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;

        if(worst != -1){
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("+-----------+--------------+-------------+\n");
    printf("| %-9s | %-12s | %-11s |\n","Process","Size","Block No");
    printf("+-----------+--------------+-------------+\n");
    for(int i=0;i<n;i++)
        printf("| %-9d | %-12d | %-11d |\n",i+1,processSize[i],
               allocation[i] != -1 ? allocation[i]+1 : 0);
    printf("+-----------+--------------+-------------+\n");
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = 5, n = 4;

    int block1[] = {100,500,200,300,600};
    int block2[] = {100,500,200,300,600};
    int block3[] = {100,500,200,300,600};

    firstFit(block1,m,processSize,n);
    bestFit(block2,m,processSize,n);
    worstFit(block3,m,processSize,n);

    return 0;
}

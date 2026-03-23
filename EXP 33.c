#include <stdio.h>

int main() {
    int ref[] = {7,0,1,2,0,3,0,4};
    int f[3] = {-1,-1,-1};
    int i,j,k,pos,far,idx,fault=0;

    printf("Page\tF1\tF2\tF3\n");

    for(i=0;i<8;i++){
        int hit=0;
        for(j=0;j<3;j++)
            if(f[j]==ref[i]) hit=1;

        if(!hit){
            far=-1;
            for(j=0;j<3;j++){
                pos=99;
                for(k=i+1;k<8;k++)
                    if(f[j]==ref[k]){ pos=k; break; }
                if(pos>far){ far=pos; idx=j; }
            }
            f[idx]=ref[i];
            fault++;
        }

        printf("%d\t%d\t%d\t%d\n",ref[i],f[0],f[1],f[2]);
    }

    printf("Page Faults = %d",fault);
}

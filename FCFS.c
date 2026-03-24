#include <stdio.h>

int main() {
    int n,i,bt[10], wt=0;
    float aw=0, at=0;
    printf("enter number of processes: ");
    scanf("%d",&n);

    printf("Enter burst names:");
    
    for(i=0;i<n;i++) 
      scanf("%d",&bt[i]);


    printf("Process  BT \t WT \t TAT\n");

    for(i=0;i<n;i++){
        printf("P%d \t %d \t %d \t %d \n", i+1, bt[i], wt, wt+bt[i]);
        aw += wt;
        at += wt + bt[i];
        wt += bt[i];
    }
    printf("Avg wait time = %f", aw/n);
    printf("Avg Turn time = %f", at/n);
}

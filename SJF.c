#include <stdio.h>


int main(){
  int burst[10], tat=0, wt=0;
  int n, total_wt=0, total_tat=0;

  printf("enter num of processes:");
  scanf("%d", &n);

  printf("Enter burst times");
  for (int i=0; i<n; i++)
    scanf("%d", &burst[i]);


  for (int i=0; i<n; i++){
    for (int j =0; j<n; j++){
      if (burst[i] < burst[j]){
        int temp = burst[i];
        burst[i] = burst[j];
        burst[j] = temp;
      }
    }
  }

  printf("Process  BT \t WT \t TAT\n");
  for (int i=0; i<n; i++){
    tat += burst[i];
    printf("P%d \t %d \t %d \t %d \n", i+1, burst[i], wt, tat);

    total_wt += wt;
    total_tat += tat;

    wt += burst[i];
  }
  

  printf("AVG wait time: %f", total_wt/n);
  printf("AVG turn around time: %f", total_tat/n);
}

#include <stdio.h>

int main(){
  int wt[10], tat[10], rt[10], burst[10];
  int avg_wt=0, avg_tat=0;
  int n, tq, time;


  printf("enter the num of proceses: ");
  scanf("%d", &n);

  printf("enter the burst times: ");
  for (int i =0; i<n; i++){
    scanf("%d", &burst[i]);
    rt[i] = burst[i];
  }
  
  printf("enter the time quanta: ");
  scanf("%d", &tq);

  while (1){
  int done = 1;
  for(int i=0; i<n; i++){
    if (rt[i] > 0){
      done = 0;
      if (rt[i] > tq){
        time += tq;
        rt[i] -= tq;
      } else {
        time += rt[i];
        rt[i] = 0;
        wt[i] += time - burst[i];
      }
    }
  }

  if (done) break;
  }

  for (int i =0; i<n; i++){
    tat[i] = wt[i] + burst[i];
    avg_wt += wt[i];
    avg_tat += tat[i];
  }

  for (int i =0; i<n; i++){
    printf("P%d \t %d \t %d \t %d \n", i+1, burst[i], wt[i], tat[i]);
  }

  printf("AVG wait time: %f", avg_wt/n);
  printf("Avg TAT time: %f", avg_tat/n);
}

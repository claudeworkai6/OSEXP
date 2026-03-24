#include <stdio.h>

int main(){
  int burst[10], priority[10], wt=0, tat=0;
  float total_wt=0, total_tat=0;
  int n, temp;

  printf("enter the num of processes:");
  scanf("%d", &n);

  printf("enter the burst times:");
  for(int i=0; i<n; i++)
    scanf("%d", &burst[i]);

  printf("enter the priority times:");
  for (int i=0; i<n; i++)
    scanf("%d", &priority[i]);

  for(int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (priority[i] > priority[j]){
        temp = priority[i];
        priority[i] = priority[j];
        priority[j] = temp;

        temp = burst[i];
        burst[i] = burst[j];
        burst[j] = temp;
      }
    }
  }

  for (int i =0; i<n; i++){
    tat += burst[i];
    printf("P%d \t %d \t %d \t %d\n", i+1, burst[i], wt, tat);
    
    total_tat += tat;
    total_wt += wt;

    wt += burst[i];
  }


  printf("Avg tat: %f\n", total_tat/n);
  printf("Avg wt: %f", total_wt/n);
}

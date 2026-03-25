#include<stdio.h>
#define PROCESSES 5
#define RESOURCES 3

int main(){
 int allocation[PROCESSES][RESOURCES]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
 int max[PROCESSES][RESOURCES]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
 int available[RESOURCES]={3,3,2},need[PROCESSES][RESOURCES],finish[PROCESSES]={0},work[RESOURCES],safeSeq[PROCESSES];
 int i,j,k,completed=0;

 for(i=0;i<PROCESSES;i++)
 for(j=0;j<RESOURCES;j++)
  need[i][j]=max[i][j]-allocation[i][j];

 for(i=0;i<RESOURCES;i++) work[i]=available[i];

 while(completed<PROCESSES){
  int found=0;
  for(i=0;i<PROCESSES;i++) if(!finish[i]){
   for(j=0;j<RESOURCES && need[i][j]<=work[j];j++);
   if(j==RESOURCES){
    for(k=0;k<RESOURCES;k++) work[k]+=allocation[i][k];
    safeSeq[completed++]=i; finish[i]=1; found=1;
   }
  }
  if(!found){ printf("NOT SAFE"); return 0; }
 }

 printf("SAFE\n");
 for(i=0;i<PROCESSES;i++) printf("P%d ",safeSeq[i]);
}

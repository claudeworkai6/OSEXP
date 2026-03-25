#include<stdio.h>
#define P 5
#define R 3

int main(){
 int alloc[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
 int max[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
 int avail[R]={3,3,2};

 int need[P][R],finish[P]={0},work[R],i,j,k,c=0;

 for(i=0;i<P;i++)
 for(j=0;j<R;j++)
  need[i][j]=max[i][j]-alloc[i][j];

 for(i=0;i<R;i++) work[i]=avail[i];

 while(c<P){
  int f=0;
  for(i=0;i<P;i++){
   if(!finish[i]){
    for(j=0;j<R;j++)
     if(need[i][j]>work[j]) break;

    if(j==R){
     for(k=0;k<R;k++) work[k]+=alloc[i][k];
     finish[i]=1; c++; f=1;
    }
   }
  }
  if(!f){ printf("UNSAFE"); return 0; }
 }

 printf("SAFE");
}

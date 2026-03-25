#include<stdio.h>
#define P 5
#define R 3

int main(){
 int a[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
 int m[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
 int av[R]={3,3,2},n[P][R],f[P]={0},w[R],s[P];
 int i,j,k,c=0;

 for(i=0;i<P;i++)
 for(j=0;j<R;j++)
  n[i][j]=m[i][j]-a[i][j];

 for(i=0;i<R;i++) w[i]=av[i];

 while(c<P){
  int ok=0;
  for(i=0;i<P;i++) if(!f[i]){
   for(j=0;j<R && n[i][j]<=w[j];j++);
   if(j==R){
    for(k=0;k<R;k++) w[k]+=a[i][k];
    s[c++]=i; f[i]=1; ok=1;
   }
  }
  if(!ok){ printf("NOT SAFE"); return 0; }
 }

 printf("SAFE\n");
 for(i=0;i<P;i++) printf("P%d ",s[i]);
}

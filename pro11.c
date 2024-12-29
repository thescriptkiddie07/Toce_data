#include<stdio.h>
#include<stdlib.h>
int n,a[10][10],i,j,source,s[10],choice;
void bfs(int n,int a[10][10],int source,int s[]){
int q[10],u,front=1,rear=1;
s[source]=1;
q[rear]=source;
while(front<=rear){
u=q[front];
front++;
for(i=1;i<=n;i++)
if(a[u][i]==1&&s[i]==0){
rear++;
q[rear]=i;
s[i]=1;
}}}
int main(){
printf("Enter number of nodes : ");
scanf("%d",&n);
printf("\nEnter adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
while(1){
printf("\n1.BFS 2.Exit\n");
scanf("%d",&choice);
switch(choice){
case 1:
printf("\nEnter source : ");
scanf("%d",&source);
for(i=1;i<=n;i++)s[i]=0;
bfs(n,a,source,s);
for(i=1;i<=n;i++)
printf("\nNode %d is %sreachable",i,s[i]==0?"not ":"");
break;
case 2:
exit(0);}}}
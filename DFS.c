#include<stdio.h>
 int visited[7]={0};
 int src=0;
 void dfs(int n,int graph[][n],int src)
 {
     for(int i=0;i<n;i++)
     {
         if(graph[src][i]==1 && visited[i]==0)
         {
             visited[i]=1;
             dfs(n,graph,i);
         }
     }
     printf("%d ",src);
 }
 int main()
 {
     int n=7;
     int graph[7][7]={{0,1,1,1,0,0,0},{1,0,0,0,1,1,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,1},{0,1,0,0,0,0,0},{0,1,0,0,0,0,0},{0,0,0,1,0,0,0}};
     visited[src]=1;
     dfs(n,graph,src);
 }

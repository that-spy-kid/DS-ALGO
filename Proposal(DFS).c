#include<stdio.h>
#define Max 10001
int graph[Max][Max];
int level[Max];
int height = 0;
int n;

void dfs(int src, int visited[])
{
  visited[src]=1;
  level[src]=height;
  height++;
  for(int i=1;i<=n;i++)
  {
    if(graph[src][i] && !visited[i])
    {
      dfs(i,visited);
    }
  }
  height--;
}

int main()
{
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    int u , v;
    scanf("%d %d",&u,&v);
    graph[u][v]=1;
    graph[v][u]=1;
  }
  int visited[n+1];
  for(int i=1;i<=n;i++) visited[i]=0;
  int src=1;
 visited[src]=1;
  dfs(src,visited);
  int q;
  scanf("%d",&q);
  int minh=Max,minid=Max;
  while(q--)
  {
    int node;
    scanf("%d",&node);
    if(level[node] < minh)
    {
      minh=level[node];
      minid=node;
    }
    if(level[node]==minh)
    {
      if(node<minid)
      {
        minid=node;
      }
    }
  }
  printf("%d",minid);
  return 0;
}

























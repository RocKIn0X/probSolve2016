#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_N  100000

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
stack<int> mystack;
queue<int> myqueue;

void print_output()
{
  for (int i=0; i<n; i++)
  {
    printf("%d: ", i+1);
    for (int j=0; j<deg[i]; j++)
      printf("%d  ", adj[i][j]+1);
    printf("\n");
  }
}

void read_input()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++)
  {
    deg[i] = 0;
  }

  for(int i=0; i<m; i++)
  {
    int u,v;
    scanf("%d %d",&u,&v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void init()
{
  for(int i=0; i<n; i++)
    visited[i] = false;
}

void dfs_stack(int u)
{
  mystack.push(u);
  while(!mystack.empty())
  {
    int node = mystack.top();
    mystack.pop();

    if (visited[node]) continue;
    printf("%d\n", node+1);

    visited[node] = true;
    for (int i=deg[node]-1; i>=0; i--)
    {
      int v = adj[node][i];
      mystack.push(v);
    }
  }
}

void dfs(int u)
{
  visited[u] = true;
  for (int i=0; i<deg[u]; i++)
  {
    int v = adj[u][i];
    if (!visited[v])
    {
      printf("%d\n", v+1);
      dfs(v);
    }
  }
}

void bfs(int u)
{
  myqueue.push(u);
  while(!myqueue.empty())
  {
    int node = myqueue.front();
    myqueue.pop();

    if (visited[node]) continue;
    printf("%d\n", node+1);

    visited[node] = true;
    for (int i=0; i<deg[node]; i++)
    {
      int v = adj[node][i];
      myqueue.push(v);
    }
  }
}

int main()
{
  read_input();
  printf("data\n\n");
  print_output();
  init();
  printf("\n\ndfs\n\n");
  dfs_stack(0);
  init();
  printf("\n\nbfs\n\n");
  bfs(0);

  return 0;
}

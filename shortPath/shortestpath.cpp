#include <vector>
#include <cstdio>
#include <climits>
#include <map>
#include <queue>
#define MAX_N 100000
#define MAX_M 200000

using namespace std;

typedef pair<int,int> node_pair; // node a to nodeb
typedef pair<int,int> dist_pair; // dist and dest node

struct cmplass {
  bool operator()(dist_pair a, dist_pair b) {
    return a.first > b.first;
  }
};

int n, m, dist, src, dest;
int node[MAX_N];
int deg[MAX_M];
bool visited[MAX_N];
vector<int> adj[MAX_N];

map<node_pair, int> edge;
priority_queue<dist_pair,vector<dist_pair>,cmplass> myqueue;

void read_input() {
  scanf("%d %d", &n, &m);
  src = 0;
  dest = n-1;
  for(int i = 0; i < n; i++) {
    deg[i] = 0;
    node[i] = INT_MAX;
  }

  node[src] = 0;
  edge[node_pair(0,0)] = 0;

  for(int i = 0; i < m; i++) {
    int u, v, dist;
    scanf(" %d %d %d", &u, &v, &dist); u--; v--;
    edge[node_pair(u,v)] = dist;
    edge[node_pair(v,u)] = dist;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

void init() {
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
}
void shortestPath(int u) {
  int srcNode = u;

  while (visited[dest] != true) {
    visited[srcNode] = true;

    for (int i = 0; i < deg[srcNode] ; i++) {
      int destNode = adj[srcNode][i];

      if (visited[destNode] != true && edge[node_pair(srcNode,destNode)] + node[srcNode] < node[destNode]) {
        node[destNode] = edge[node_pair(srcNode,destNode)] + node[srcNode];
        myqueue.push(dist_pair(node[destNode], destNode));
      }
    }
    
    srcNode = myqueue.top().second;
    myqueue.pop();
  }
}

int main () {
  int count = 0;

  init();
  read_input();
  shortestPath(0);

  printf("%d\n", node[dest]);
}

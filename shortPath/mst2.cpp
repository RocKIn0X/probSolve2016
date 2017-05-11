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

int n, m, dist, src, sumDist;
int node[MAX_N];
int deg[MAX_M];
bool visited[MAX_N];
vector<int> adj[MAX_N];

map<node_pair, int> edge;
priority_queue<dist_pair,vector<dist_pair>,cmplass> myqueue;

void read_input() {
  scanf("%d %d", &n, &m);
  src = 0;
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
void mstPrim(int u) {
  int srcNode = u;
  sumDist = 0;

  for (int count = 0; count < n-1; count++) {
    for (int i = 0; i < deg[srcNode]; i++) {
      int destNode = adj[srcNode][i];

      if (visited[destNode] == false && edge[node_pair(srcNode,destNode)] < node[destNode]) {
        node[destNode] = edge[node_pair(srcNode,destNode)];
        myqueue.push(dist_pair(node[destNode], destNode));
      }
    }

    visited[srcNode] = true;

    do {
      srcNode = myqueue.top().second;
      myqueue.pop();
    } while (visited[srcNode] == true);

    sumDist += node[srcNode];
  }
}

int main () {
  init();
  read_input();
  mstPrim(0);

  printf("%d\n", sumDist);
}

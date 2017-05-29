#include <vector>
#include <cstdio>
#include <queue>
#define MAX_N 100000
#define MAX_M 200000

using namespace std;

int n, m, c;

vector<int> adj[MAX_N];
queue<int> myqueue;
int deg[MAX_M];
int state[MAX_N];

void read_input() {
  scanf(" %d %d %d", &n, &m, &c);
  for(int i = 0; i < n; i++) {
    deg[i] = 0;
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v); u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool visited[MAX_N];
bool looked[MAX_N];

void init() {
  queue<int> empty;
  swap(myqueue, empty);

  for(int i=0; i<n; i++) {
    visited[i] = false;
    looked[i] = false;
    state[i] = 3; //default state
    adj[i].clear();
  }
}

int bfs(int u, int c) {
  int sum = 0;
  int lv = 0;
  int adjNode = 1; //init node
  myqueue.push(u);
  while(lv == c) {
    int node = myqueue.front();
    myqueue.pop();

    if (visited[node]) continue;
    adjNode--;
    if (adjNode == 0) {
      lv++;
    }
    visited[node] = true;
    for (int i=0; i<deg[node]; i++) {
      int v = adj[node][i];
      myqueue.push(v);
      if (looked[v] != true) {
        sum += 1;
        looked[v] = true;
      }
    }
  }

  return sum;
}

int main () {
  int sum = 0;
  read_input();
  init();

  for (int i = 0; i < n; i++) {
    init();
    int temp = bfs(i, c);

    if (temp > sum) {
      sum = temp;
    }
  }

  printf("%d\n", sum);

  return 0;
}

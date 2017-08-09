#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#define MAX_N 100000
#define MAX_M 200000

using namespace std;

int n, m, k, h;

vector<int> adj[MAX_N];
queue<int> myqueue;
map<int, int> levelMap;
int deg[MAX_M];
int state[MAX_N];
int hos[MAX_N];
int quality[MAX_N];

void read_input() {
  scanf(" %d %d %d %d", &n, &m, &k, &h);
  for(int i = 0; i < n; i++) {
    deg[i] = 0;
  }

  for (int i = 0; i < k; i++) {
    cin >> hos[i];
  }

  for (int i = 0; i < k; i++) {
    cin >> quality[i];
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
  int sum = 1;
  int lv = 1;
  int adjNode = 1; //init node
  myqueue.push(u);
  looked[u] = true;
  while(!myqueue.empty()) {
    int node = myqueue.front();
    myqueue.pop();

    if (levelMap[node] == c+1) break;
    if (visited[node]) continue;

    visited[node] = true;

    for (int i=0; i<deg[node]; i++) {
      int v = adj[node][i];
      
      if (looked[v] != true && levelMap[node]+1 <= c) {
        sum += 1;
        looked[v] = true;
        myqueue.push(v);
        levelMap[v] = levelMap[node] + 1;
      }
    }
  }

  return sum;
}

int main () {
  int sum = 0;
  int temp;
  read_input();
  init();

  for (int i = 0; i < k; i++) {
    temp = bfs(hos[i], quality[i] + h);
    levelMap.clear();

    sum += temp;
  }

  printf("%d\n", sum);

  return 0;
}
#include <vector>
#include <cstdio>
#include <queue>
#define MAX_N 100000
#define MAX_M 200000

using namespace std;

int n, m;

vector<int> adj[MAX_N];
queue<int> myqueue;
int deg[MAX_M];
int state[MAX_N];

void read_input() {
  scanf("%d %d", &n, &m);
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

void init() {
  queue<int> empty;
  swap(myqueue, empty);

  for(int i=0; i<n; i++) {
    visited[i] = false;
    state[i] = 3; //default state
    adj[i].clear();
  }
}

bool bfs(int u) {
  state[u] = 1;
  myqueue.push(u);
  while(!myqueue.empty()) {
    int node = myqueue.front();
    myqueue.pop();

    if (visited[node]) continue;
    //printf("%d\n", node+1);

    visited[node] = true;
    for (int i=0; i<deg[node]; i++) {
      int v = adj[node][i];
      myqueue.push(v);

      //printf("node: %d, v: %d, stateN: %d, stateV: %d\n", node+1, v+1, state[node], state[v]);
      if (state[node] == state[v]) {
        return false;
      }

      if (state[node] == 1) {
        state[v] = 2;
      } else if (state[node] == 2) {
        state[v] = 1;
      }
    }
  }

  return true;
}

int main () {
  int num;
  bool check;
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    read_input();
    init();

    for (int j = 0; j < n; j++) {
      if (visited[j] == false) {
        if (bfs(j)) {
          //printf("yes %d\n", j);
          check = true;
        } else {
          //printf("no %d\n", j);
          check = false;
          break;
        }
      }
    }

    if (check) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}

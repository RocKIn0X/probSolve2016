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

void init_bpt() {
  for (int i = 0; i < n; i++) {
    state[i] = 3; //default state
  }
}

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
  for(int i=0; i<n; i++)
    visited[i] = false;
}

bool bfs(int u) {
  bool check = true;

  myqueue.push(u);
  state[u] = 1;
  while(!myqueue.empty()) {
    int node = myqueue.front();
    myqueue.pop();

    if (visited[node]) continue;
    //printf("%d\n", node+1);

    visited[node] = true;
    for (int i=0; i<deg[node]; i++) {
      int v = adj[node][i];
      if (!visited[v]) {
        myqueue.push(v);
      }

      if (state[v] == 3) {
        if (state[node] == 1) {
          state[v] = 2;
          //printf("%d %d\n", v, state[v]);
        } else if (state[node] == 2) {
          state[v] = 1;
          //printf("%d %d\n", v, state[v]);
        }
      } else {
        //printf("node: %d v: %d stateNode: %d stateV: %d\n", node, v, state[node], state[v]);
        //printf("%s\n", (state[node] == state[v]) ? "true" : "false");
        if (state[node] == state[v]) {
          printf("hey\n");
          check = false;
          break;
          //printf("%s\n", (state[node] == state[v]) ? "true" : "false");
        }
      }
    }

    if (check == false) {
      return false;
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
    init_bpt();

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

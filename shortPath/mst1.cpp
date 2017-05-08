#include <cstdio>
#include <queue>

using namespace std;

typedef int valueType;
typedef pair<int,int> node_pair;
typedef pair<int,node_pair> w_pair;

struct Node {
  valueType val;
  Node* parent;

  Node(valueType val, Node* parent = 0)
    : val(val), parent(parent) {}
};

struct cmplass {
  bool operator()(w_pair a, w_pair b) {
    return a.first > b.first;
  }
};

Node* node[1005];
priority_queue<w_pair,vector<w_pair>,cmplass> q;

void makeSet(int x) {
  node[x] = new Node(x+1);
  node[x]->parent = node[x];
}

Node* find(Node* x) {
  if (x->parent != x) {
    x->parent = find(x->parent);
  }
  return x->parent;
}

void unionNode(Node* x, Node* y) {
  Node* xRoot = find(x);
  Node* yRoot = find(y);
  xRoot->parent = yRoot;
}

void init(int n) {
  for (int i = 0; i < n; i++) {
    makeSet(i);
  }
}

bool check(Node* x, Node* y) {
  Node* xRoot = find(x);
  Node* yRoot = find(y);

  if (xRoot->val == yRoot->val) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  init(n);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf(" %d %d %d", &a, &b, &w);

    q.push(w_pair(w, node_pair(a,b)));
  }

  int minWeight = 0;

  for (int i = 0; i < m; i++) {
    w_pair temp = q.top();
    q.pop();
    int tempX = temp.second.first - 1;
    int tempY = temp.second.second - 1;

    if (!check(node[tempX], node[tempY])) {
      minWeight += temp.first;
      unionNode(node[tempX], node[tempY]);
    }
  }

  printf("%d\n", minWeight);

  return 0;
}

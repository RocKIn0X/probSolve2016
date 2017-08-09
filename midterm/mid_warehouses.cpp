#include <cstdio>

using namespace std;

typedef int valueType;

struct Node {
  valueType val;
  Node* parent;

  Node(valueType val, Node* parent = 0)
    : val(val), parent(parent) {}
};

Node* node[100005];

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
  int n, m, k, a, b;

  scanf(" %d %d %d", &n, &m, &k);

  init(n);

  for (int i = 0; i < m; i++) {
      scanf (" %d %d", &a, &b); a--; b--;

      unionNode(node[a], node[b]);
  }

  for (int i = 0; i < k; i++) {
      scanf (" %d %d", &a, &b); a--; b--;

      if( check(node[a], node[b]) ) {
        printf("1\n");
      } else {
        printf("0\n");
      }
  }

  return 0;
}

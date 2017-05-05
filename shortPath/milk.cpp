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
  int n, q;

  scanf("%d %d", &n, &q);

  init(n);

  for (int i = 0; i < q; i++) {
    char op;
    int x, y;

    scanf(" %c %d %d", &op, &x, &y); x--; y--;

    if (op == 'q') {
      if( check(node[x], node[y]) ) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else if (op == 'c') {
      unionNode(node[x], node[y]);
    }
  }

  return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode {
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode (valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void insert(TreeNode*& node, valueType v) {
  if (node == 0) {
    printf("hey\n");
    node = new TreeNode(v);
  } else {
    printf("hello\n");
    if (v < node->val) {
      insert (node->left, v);
    } else {
      insert (node->right, v);
    }
  }
}

bool find(TreeNode*& node, valueType v) {
  if (node == 0) {
    return false;
  } else {
    if (v == node->val) {
      return true;
    } else {
      if (v < node->val) {
        find(node->left, v);
      } else {
        find(node->right, v);
      }
    }
  }
}

bool checkNode(TreeNode*& node) {
  if (node != 0) {
    return true;
  }

  return false;
}

int main () {
  int n, op, key;
  TreeNode* root = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &op, &key);

    if (op == 1) {
      insert(root, key);
    } else if (op == 2) {
      if (find(root, key)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }

  return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode {
  valueType val;
  valueType right_LV;
  valueType left_LV;
  TreeNode* left;
  TreeNode* right;

  TreeNode (valueType val,  valueType right_LV=0, valueType left_LV=0,
            TreeNode* left=0, TreeNode* right=0)
    : val(val), right_LV(right_LV), left_LV(left_LV), left(left), right(right) {}
};

void insert (TreeNode*& node, valueType v) {
  if (!node) {
    node = new TreeNode(v);
  } else {
    if (v < node->val) {
      node->left_LV += 1;
      insert (node->left, v);
    } else {
      node->right_LV += 1;
      insert (node->right, v);
    }
  }
}

int count (TreeNode*& node, valueType v) {
  if (node == 0) {
    return 0;
  }

  if (v > node->val) {
    return count(node->right, v);
  } else if (v < node->val) {
    return 1 + node->right_LV + count(node->left, v);
  } else if (v == node->val) {
    return node->right_LV;
  }
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
      printf("%d\n", count(root, key));
    }
  }

  return 0;
}

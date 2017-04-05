#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode {
  valueType val;
  valueType lv;
  valueType right_LV;
  valueType left_LV;
  TreeNode* left;
  TreeNode* right;

  TreeNode (valueType val, valueType lv=0,
            valueType right_LV=0, valueType left_LV=0,
            TreeNode* left=0, TreeNode* right=0)
    : val(val), lv(lv), right_LV(right_LV), left_LV(left_LV), left(left), right(right) {}
};

void insert (TreeNode*& node, valueType v) {
  if (!node) {
    node = new TreeNode(v);
  } else {
    if (v < node->val) {
      node->left_LV += 1;
      insert (node->left, v);
      node->left->lv = node->lv + 1;
    } else {
      node->right_LV += 1;
      insert (node->right, v);
      node->right->lv = node->lv + 1;
    }
  }
}

void printNode (TreeNode*& node, valueType lv) {
  for (int i = 0; i < lv; i++) {
    printf("...");
  }

  printf("* %d\n", node->val);
}

void postOrder(TreeNode*& node) {
  if (!node) {
    return;
  }

  postOrder(node->right);
  printNode(node, node->lv);
  postOrder(node->left);
}

int main () {
  int n, key;
  TreeNode* root = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &key);
    insert(root, key);
  }

  postOrder(root);

  return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

typedef int valueType;

struct TreeNode {
  valueType val;
  int height;
  TreeNode* left;
  TreeNode* right;

  TreeNode (valueType val,  int height=0,
            TreeNode* left=0, TreeNode* right=0)
    : val(val), height(height), left(left), right(right) {}

  void update_height() {
    int lh = (left == 0) ? -1 : left->height;
    int rh = (right == 0) ? -1 : right->height;
    height = (lh > rh) ? lh + 1 : rh + 1;
  }
};

void left_rotation (TreeNode*& node) {
  TreeNode* a = node;
  TreeNode* b = node->right;
  TreeNode* T1 = b->left;

  a->right = T1;
  b->left = a;
  node = b;

  a->update_height();
  b->update_height();
}

void right_rotation (TreeNode*& node) {
  TreeNode* a = node;
  TreeNode* b = node->left;
  TreeNode* T1 = b->right;

  a->left = T1;
  b->right = a;
  node = b;

  a->update_height();
  b->update_height();
}

void insert (TreeNode*& node, valueType v) {
  if (!node) {
    node = new TreeNode(v);
  } else {
    if (v < node->val) {
      insert (node->left, v);
    } else {
      insert (node->right, v);
    }
  }

  node->update_height();

  int lh = (node->left == 0) ? -1 : node->left->height;
  int rh = (node->right == 0) ? -1 : node->right->height;

  if (rh > lh+1) {
    if (v > node->right->val) {
      left_rotation(node);
    } else {
      right_rotation(node->right);
      left_rotation(node);
    }
  } else if (lh > rh+1) {
    if (v < node->left->val) {
      right_rotation(node);
    } else {
      left_rotation(node->left);
      right_rotation(node);
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
        return find(node->left, v);
      } else {
        return find(node->right, v);
      }
    }
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
      if (find(root, key)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }

  return 0;
}

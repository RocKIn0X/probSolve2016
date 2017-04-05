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
    //printf("hey\n");
    node = new TreeNode(v);
  } else {
    //printf("hello\n");
    if (v < node->val) {
      insert (node->left, v);
    } else if (v > node->val) {
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
        return find(node->left, v);
      } else {
        return find(node->right, v);
      }
    }
  }
}

TreeNode* findNode(TreeNode*& node, valueType v) {
  if (node == 0) {
    return '\0';
  } else {
    if (v == node->val) {
      return node;
    } else {
      if (v < node->val) {
        return findNode(node->left, v);
      } else {
        return findNode(node->right, v);
      }
    }
  }
}

TreeNode* minNode(TreeNode* node) {

  if (node->left == 0) {
    return node;
  }

  return minNode(node->left);
}

TreeNode* deleteNode(TreeNode* node, valueType v) {
  if (node == 0) {
    return 0;
  }

  if (v > node->val) {
    node->right = deleteNode(node->right, v);
  } else if (v < node->val) {
    node->left = deleteNode(node->left, v);
  } else {
    TreeNode* temp;

    if (node->left and node->right) {
      temp = minNode(node->right);
      node->val = temp->val;

      node->right = deleteNode(node->right,temp->val);
    } else if (node->left) {
      temp = node;
      node = node->left;

      delete temp;
    } else if (node->right) {
      temp = node;
      node = node->right;

      delete temp;
    } else {
      delete node;
      node = '\0';
    }
  }

  return node;
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
      } else if (op == 3) {
        root = deleteNode(root, key);
      }
    }

  return 0;
}

#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int mostLeft = 0;
int mostRight = 0;

map<int, int> sum;

struct TreeNode {
  int val;
  int pos;
  TreeNode* left;
  TreeNode* right;

  TreeNode (int val, int pos,
            TreeNode* left=0, TreeNode* right=0)
    : val(val), pos(pos), left(left), right(right) {}
};

void insert (TreeNode*& node, int v, int pos) {
  if (!node) {
    node = new TreeNode(v, pos);
  } else {
    if (pos < node->pos) {
        mostLeft = pos;
        insert (node->left, v, pos);
    } else if (pos == node->pos) {
        if (node->right != '\0') {
            insert (node->right, v, pos);
        } else if (node->left != '\0') {
            insert (node->left, v, pos);
        } else if (node->left != '\0' && node->right != '\0') {
            insert (node->right, v, pos);
        }
    } else {
        mostRight = pos;
        insert (node->right, v, pos);
    }
  }
}

void find_sum (TreeNode*& node) {
    if (!node) {
        return;   
    }

    sum[node->pos + mostLeft] += node->val;

    find_sum (node->left);
    find_sum (node->right);
}

void print_sum () {
    for (map<int, int>::iterator it=sum.begin(); it!=sum.end(); ++it) {
        if (it == sum.begin()) {
            printf ("%d", it->second);
        } else {
            printf (" %d", it->second);
        }
    }

}

TreeNode* reset_tree (TreeNode*& node) {
    if (!node) {
        return 0;
    } else {
        reset_tree (node->left);
        reset_tree (node->right);
        delete node;
        node = '\0';
        return node;
    }
}

int main () {
    int val, pos, count;
    TreeNode* root = 0;
    count = 1;

    while (true) {
        pos = 0;
        mostRight = pos;
        mostLeft = pos;

        scanf(" %d ", &val);

        if (val == -1) {
            break;
        }

        insert (root, val, pos);

        while (true) {
            scanf(" %d ", &val);

            if (val != -1) {
                insert (root, val, --pos);
            } else {
                pos += 2;

                if (pos - mostRight > 2) {
                    break;
                }
            }            
        }
        
        find_sum (root);
        printf ("Case %d:\n", count++);
        print_sum ();
        cout << endl << endl;

        reset_tree (root);
    }

    return 0;
}
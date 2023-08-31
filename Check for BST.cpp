#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
  int data;
  Node* left, * right;
};

class Solution {
public:
  int isBSTUtil(Node* node, int min, int max) {
    if (!node) return 1;
    if (node->data < min || node->data > max) return 0;
    return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
  }
  bool isBST(Node* root) {
    isBSTUtil(root, INT_MIN, INT_MAX);
  }

};
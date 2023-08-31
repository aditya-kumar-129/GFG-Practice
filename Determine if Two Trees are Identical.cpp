#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left, * right;
};

class Solution {
public:
  bool isIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 && root2) return false;
    if (root1 && !root2) return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool ans = root1->data == root2->data;
    if (left && right && ans) return true;
    return false;
  }
};
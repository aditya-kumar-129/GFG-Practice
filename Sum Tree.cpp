#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left, * right;
};

class Solution {
public:
  int returnSum(Node* root) {
    if (!root) return 0;
    return (root->data + returnSum(root->left) + returnSum(root->right));
  }

  bool isSumTree(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if ((returnSum(root->left) + returnSum(root->right) == root->data) && isSumTree(root->left) && isSumTree(root->right))
      return true;
    return false;
  }
};
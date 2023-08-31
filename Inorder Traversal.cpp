#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left, * right;
};

class Solution {
  void dfs(Node* root, vector<int>& x) {
    if (root) {
      dfs(root->left, x);
      x.push_back(root->data);
      dfs(root->right, x);
    }
  }

public:
  vector<int> inOrder(Node* root) {
    vector<int> v;
    dfs(root, v);
    return v;
  }
};
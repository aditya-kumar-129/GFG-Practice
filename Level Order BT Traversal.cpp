#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left, * right;
};

class Solution {
public:
  vector<int> levelOrder(Node* node) {
    queue<Node*> q;
    vector<int> V;
    if (!node) return V;
    q.push(node);
    while (!q.empty()) {
      Node* root = q.front();
      if (root->left) q.push(root->left);
      if (root->right) q.push(root->right);
      V.push_back(root->data);
      q.pop();
    }
    return V;
  }
};
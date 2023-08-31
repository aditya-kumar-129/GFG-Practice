#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left, * right;
};

void rec(vector<int>& ans, struct Node* root, int level) {
  if (root == nullptr) return;
  if (level == ans.size()) ans.push_back(root->data);
  rec(ans, root->left, level + 1);
  rec(ans, root->right, level + 1);
}
vector<int> leftView(Node* root) {
  vector<int> ans;
  rec(ans, root, 0);
  return ans;
}
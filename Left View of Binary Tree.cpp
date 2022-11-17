#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* newNode(int val)
{
  Node* temp = new Node;
  temp->data = val;
  temp->left = nullptr;
  temp->right = nullptr;
  return temp;
}

void leftViewUtil(vector<int>& ans, struct Node* root, int level)
{
  if (root == nullptr) return;
  if (level == ans.size())
    ans.push_back(root->data);
  leftViewUtil(ans, root->left, level + 1);
  leftViewUtil(ans, root->right, level + 1);
}
vector<int> leftView(Node* root)
{
  vector<int> ans;
  leftViewUtil(ans, root, 0);
  return ans;
}
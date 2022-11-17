#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

class Solution
{
  void INORDER(Node* root, vector<int>& x)
  {
    if (root != nullptr)
    {
      INORDER(root->left, x);
      x.push_back(root->data);
      INORDER(root->right, x);
    }
  }

public:
  vector<int> inOrder(Node* root)
  {
    vector<int> v;
    INORDER(root, v);
    return v;
  }
};
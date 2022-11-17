#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

class Solution
{
public:
  int isBSTUtil(Node* node, int min, int max)
  {
    if (node == nullptr)
      return 1;
    if (node->data < min || node->data > max)
      return 0;
    return
      isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
  }
  bool isBST(Node* root)
  {
    isBSTUtil(root, INT_MIN, INT_MAX);
  }

};

void inorder(Node* root, vector<int>& v)
{
  if (root == nullptr)
    return;
  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}
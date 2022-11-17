#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

Node* newNode(int val)
{
  Node* temp = new Node;
  temp->data = val;
  temp->left = nullptr;
  temp->right = nullptr;
  return temp;
}

class Solution
{
public:
  int returnSum(Node* root)
  {
    if (root == nullptr)
      return 0;
    return (root->data + returnSum(root->left) + returnSum(root->right));
  }

  bool isSumTree(Node* root)
  {
    if (root == nullptr)
      return true;

    if (root->left == nullptr && root->right == nullptr)
      return true;

    if ((returnSum(root->left) + returnSum(root->right) == root->data) && isSumTree(root->left) && isSumTree(root->right))
      return true;

    return false;
  }
};
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
  // Function to return the diameter of a Binary Tree.
  int diameter(Node* tree)
  {
    if (tree == nullptr)
      return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
  }
  int height(Node* node)
  {
    if (node == nullptr)
      return 0;
    return 1 + max(height(node->left), height(node->right));
  }
};
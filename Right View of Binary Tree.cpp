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

class Solution
{
public:
  vector<int> ans;
  int maxLevel = 0;
  void rightViewTree(Node* root, int level)
  {
    if (!root)
      return;
    if (maxLevel < level)
    {
      ans.push_back(root->data);
      maxLevel = level;
    }
    rightViewTree(root->right, level + 1);
    rightViewTree(root->left, level + 1);
  }
  vector<int> rightView(Node* root)
  {
    rightViewTree(root, 1);
    return ans;
  }
};
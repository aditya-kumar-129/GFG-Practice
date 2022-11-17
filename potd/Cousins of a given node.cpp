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

Node* pointer(Node* root, int n)
{
  if (root == nullptr)
    return nullptr;
  if (root->data == n)
    return root;
  Node* l = pointer(root->left, n);
  if (l != nullptr && l->data == n)
    return l;
  Node* r = pointer(root->right, n);
  return r;
}

class Solution
{
public:
  vector<int> printCousins(Node* root, Node* node_to_find)
  {
    queue<Node*> q;
    q.push(root);
    bool flag = true;
    while (!q.empty() && flag)
    {
      int size = q.size();
      for (int i = 0;i < size;i++)
      {
        auto tempNode = q.front();
        q.pop();
        if (tempNode->left == node_to_find || tempNode->right == node_to_find)
          flag = false;
        else
        {
          if (tempNode->left)
            q.push(tempNode->left);
          if (tempNode->right)
            q.push(tempNode->right);
        }
      }
    }
    vector <int> ans;
    while (!q.empty())
    {
      ans.push_back(q.front()->data);
      q.pop();
    }
    if (ans.size() == 0)
      ans.push_back(-1);
    return ans;
  }
};
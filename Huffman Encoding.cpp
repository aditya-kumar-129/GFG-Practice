#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  struct Node
  {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
      data = val;
      left = nullptr;
      right = nullptr;
    }
  };

  struct cmp
  {
    bool operator()(Node* l, Node* r)
    {
      return (l->data > r->data);
    }
  };

  void preOrder(Node* root, string s, vector<string>& ans)
  {
    if (!root)
      return;
    if (!root->left && !root->right)
      ans.push_back(s);
    preOrder(root->left, s + "0", ans);
    preOrder(root->right, s + "1", ans);
  }

  vector<string> huffmanCodes(string S, vector<int> f, int n)
  {
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
      Node* temp = new Node(f[i]);
      pq.push(temp);
    }
    while (pq.size() != 1)
    {

      Node* left = pq.top();
      pq.pop();
      Node* right = pq.top();
      pq.pop();
      Node* parent = new Node(left->data + right->data);
      parent->left = left;
      parent->right = right;
      pq.push(parent);
    }
    Node* root = pq.top();
    pq.pop();
    vector<string> ans;
    preOrder(root, "", ans);
    return ans;
  }
};
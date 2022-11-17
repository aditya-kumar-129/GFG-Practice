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

Node* buildTree(string str)
{
  if (str.length() == 0 || str[0] == 'N')
    return nullptr;
  vector<string> ip;
  istringstream iss(str);
  for (string str; iss >> str; )
    ip.push_back(str);
  Node* root = new Node(stoi(ip[0]));
  queue<Node*> queue;
  queue.push(root);
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    Node* currNode = queue.front();
    queue.pop();
    string currVal = ip[i];
    if (currVal != "N") {
      currNode->left = new Node(stoi(currVal));
      queue.push(currNode->left);
    }
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];
    if (currVal != "N") {
      currNode->right = new Node(stoi(currVal));
      queue.push(currNode->right);
    }
    i++;
  }
  return root;
}

void inorder(Node* root, vector<int>& v)
{
  if (root == nullptr)
    return;
  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}

int main() {
  int t;
  string tc;
  getline(cin, tc);
  t = stoi(tc);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if (ob.isBST(root))
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
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

Node* buildTree(string str)
{
  if (str.length() == 0 || str[0] == 'N')
    return nullptr;
  vector<string> ip;
  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);
  Node* root = newNode(stoi(ip[0]));
  queue<Node*> queue;
  queue.push(root);
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {
    Node* currNode = queue.front();
    queue.pop();
    string currVal = ip[i];
    if (currVal != "N")
    {
      currNode->left = newNode(stoi(currVal));
      queue.push(currNode->left);
    }
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];
    if (currVal != "N")
    {
      currNode->right = newNode(stoi(currVal));
      queue.push(currNode->right);
    }
    i++;
  }
  return root;
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

int main()
{

  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    cout << ob.isSumTree(root) << endl;
  }
  return 1;
}
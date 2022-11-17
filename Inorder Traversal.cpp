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

Node* buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return nullptr;

  // Creating vector of strings from input string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node* root = new Node(stoi(ip[0]));

  // Push the root to the queue
  queue<Node*> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node* currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {
      // Create the left child for the current node
      currNode->left = new Node(stoi(currVal));
      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {
      // Create the right child for the current node
      currNode->right = new Node(stoi(currVal));
      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }
  return root;
}

int main()
{
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
    vector<int> res = ob.inOrder(root);
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
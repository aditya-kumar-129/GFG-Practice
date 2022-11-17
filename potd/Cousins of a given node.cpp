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

Node* buildTree(string str)
{
  if (str.length() == 0 || str[0] == 'N')
    return nullptr;
  vector<string> ip;
  istringstream iss(str);
  for (string str; iss >> str; )
    ip.push_back(str);
  Node* root = newNode(stoi(ip[0]));
  queue<Node*> queue;
  queue.push(root);
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    Node* currNode = queue.front();
    queue.pop();
    string currVal = ip[i];
    if (currVal != "N") {
      currNode->left = newNode(stoi(currVal));
      queue.push(currNode->left);
    }
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];
    if (currVal != "N") {
      currNode->right = newNode(stoi(currVal));
      queue.push(currNode->right);
    }
    i++;
  }
  return root;
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

int main()
{
  int t;
  cin >> t;
  getchar();
  while (t--)
  {
    int n;
    cin >> n;
    getchar();
    string inp;
    getline(cin, inp);
    struct Node* root = buildTree(inp);
    Node* p = pointer(root, n);
    Solution ob;
    vector<int> ans = ob.printCousins(root, p);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
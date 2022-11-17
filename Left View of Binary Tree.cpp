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

void leftViewUtil(vector<int>& ans, struct Node* root, int level)
{
  if (root == nullptr) return;
  if (level == ans.size())
    ans.push_back(root->data);
  leftViewUtil(ans, root->left, level + 1);
  leftViewUtil(ans, root->right, level + 1);
}
vector<int> leftView(Node* root)
{
  vector<int> ans;
  leftViewUtil(ans, root, 0);
  return ans;
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

int main() {
  int t;
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    vector<int> vec = leftView(root);
    for (int x : vec)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}


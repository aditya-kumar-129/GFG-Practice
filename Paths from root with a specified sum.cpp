#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  struct Node* left, * right;
};

Node* newNode(int key)
{
  Node* temp = new Node;
  temp->key = key;
  temp->left = temp->right = nullptr;
  return (temp);
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

class Solution
{
public:
  vector<vector<int>> ans;
  void helper(Node* curr_node, int target, vector<int>& temp, int sumTillThatNode)
  {
    sumTillThatNode += curr_node->key;
    temp.push_back(curr_node->key);
    if (sumTillThatNode == target)
      ans.push_back(temp);
    if (curr_node->left)
      helper(curr_node->left, target, temp, sumTillThatNode);
    if (curr_node->right)
      helper(curr_node->right, target, temp, sumTillThatNode);
    temp.pop_back();
  }
  vector<vector<int>> printPaths(Node* root, int sum)
  {
    vector<int> temp;
    helper(root, sum, temp, 0);
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
    int sum;
    cin >> sum;
    getchar();
    string inp;
    getline(cin, inp);
    struct Node* root = buildTree(inp);
    Solution ob;
    vector<vector<int>> ans = ob.printPaths(root, sum);
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < ans[i].size(); j++)
        cout << ans[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
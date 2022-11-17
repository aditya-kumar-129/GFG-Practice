#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = right = nullptr;
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

class Solution
{
public:
  int ans;
  void kthLargestUtil(Node* root, int k, int& c)
  {
    if (root == nullptr || c >= k)
      return;
    kthLargestUtil(root->right, k, c);
    c++;
    if (c == k)
      ans = root->data;
    kthLargestUtil(root->left, k, c);
  }
  int kthLargest(Node* root, int k)
  {
    int c = 0;
    kthLargestUtil(root, k, c);
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
    string s;
    getline(cin, s);
    Node* head = buildTree(s);
    int k;
    cin >> k;
    getchar();
    Solution ob;
    cout << ob.kthLargest(head, k) << endl;
  }
  return 1;
}  

// Space complexity :- O(n)
void revin(vector<int>& ans, Node* root, int K) 
{
  if (!root)
    return;
  revin(ans, root->right, K);
  if (ans.size() >= K)
    return;
  ans.push_back(root->data);
  revin(ans, root->left, K);
}
int kthLargest(Node* root, int K)
{
  vector<int>ans;
  revin(ans, root, K);
  return ans[ans.size() - 1];
}
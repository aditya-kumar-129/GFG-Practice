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
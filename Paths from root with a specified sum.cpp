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
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

class Solution
{
public:
  //Function to return the level order traversal of a tree.
  vector<int> levelOrder(Node *node)
  {
    //Your code here
    queue<Node *> Q;
    vector<int> V;
    if (!node)
      return V;
    Q.push(node);
    while (!Q.empty())
    {
      Node *root = Q.front();
      if (root->left)
        Q.push(root->left);
      if (root->right)
        Q.push(root->right);
      V.push_back(root->data);
      Q.pop();
    }
    return V;
  }
};

void inOrder(struct Node *node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}

Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {
    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();
    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {
      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));
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
      currNode->right = newNode(stoi(currVal));
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
  scanf("%d ", &t);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    vector<int> res = ob.levelOrder(root);
    for (int i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}

/*
Below is the code to print the level by level (we can get to know in which level how many elements are present)
Litile bit important
https://www.techiedelight.com/level-order-traversal-binary-tree/
third method of the above article
*/

/*
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Traverse the tree in a preorder fashion and store nodes in a map
// corresponding to their level
void preorder(Node* root, int level, auto &map)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }
 
    // insert the current node and its level into the map
    map[level].push_back(root->key);
 
    // recur for the left and right subtree by increasing the level by 1
    preorder(root->left, level + 1, map);
    preorder(root->right, level + 1, map);
}
 
// Recursive function to print level order traversal of a given binary tree
void levelOrderTraversal(Node* root)
{
    // create an empty map to store nodes between given levels
    unordered_map<int, vector<int>> map;
 
    // traverse the tree and insert its nodes into the map
    // corresponding to their level
    preorder(root, 1, map);
 
    // iterate through the map and print all nodes between given levels
    for (int i = 1; map[i].size() > 0; i++)
    {
        cout << "Level " << i << ": ";
        for (int j: map[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}
 
int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    root->right->right->right = new Node(30);
 
    levelOrderTraversal(root);
 
    return 0;
}*/
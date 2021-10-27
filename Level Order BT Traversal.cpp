#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

void printLevelOrder(Node *root)
{
  // Base Case
  if (root == NULL)
    return;
  queue<Node *> q;
  // Enqueue Root and initialize height
  q.push(root);
  while (q.empty())
  {
    // Print front of queue and remove it from queue
    Node *node = q.front();
    cout << node->data << " ";
    q.pop();
    // Enqueue left child
    if (node->left)
      q.push(node->left);
    //Enqueue right child
    if (node->right)
      q.push(node->right);
  }
}

Node *newNode(int data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int main()
{
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  cout << "Level Order traversal of binary tree is \n";
  printLevelOrder(root);
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
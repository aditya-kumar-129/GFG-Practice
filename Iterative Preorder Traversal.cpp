#include <bits/stdc++.h>
using namespace std;
#define nullptr nullptr

// Tree Node
struct Node {
  int data;
  Node* left, * right;

  Node(int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root)
{
  if (root == nullptr)
    return;
  stack<Node*> st;
  Node* curr = root;

  // run till stack is not empty or current is not nullptr
  while (!st.empty() || curr != nullptr) {
    // Print left children while exist and keep pushing right into the stack.
    while (curr != nullptr) {
      cout << curr->data << " ";

      if (curr->right)
        st.push(curr->right);

      curr = curr->left;
    }

    // We reach when curr is nullptr, so We take out a right child from stack
    if (st.empty() == false) {
      curr = st.top();
      st.pop();
    }
  }
}

// Driver Code
int main()
{
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->left->left = new Node(70);
  root->left->right = new Node(50);
  root->right->left = new Node(60);
  root->left->left->right = new Node(80);

  preorderIterative(root);

  return 0;
}

// Method 2 :- 

// C++ program to implement iterative preorder traversal
#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node {
  int data;
  struct node* left;
  struct node* right;
};

/* Helper function that allocates a new node with the given data and
   nullptr left and right  pointers.*/
struct node* newNode(int data)
{
  struct node* node = new struct node;
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;
  return (node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node* root)
{
  // Base Case
  if (root == nullptr)
    return;

  // Create an empty stack and push root to it
  stack<node*> nodeStack;
  nodeStack.push(root);

  /* Pop all items one by one. Do following for every popped item
     a) print it
     b) push its right child
     c) push its left child
  Note that right child is pushed first so that left is processed first */
  while (nodeStack.empty() == false) {
    // Pop the top item from stack and print it
    struct node* node = nodeStack.top();
    printf("%d ", node->data);
    nodeStack.pop();

    // Push right and left children of the popped node to stack
    if (node->right)
      nodeStack.push(node->right);
    if (node->left)
      nodeStack.push(node->left);
  }
}

// Driver program to test above functions
int main()
{
  struct node* root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  return 0;
}

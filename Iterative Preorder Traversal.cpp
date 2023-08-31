#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left, * right;
};

// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node* root) {
  if (!root)return;
  stack<Node*> st;
  Node* curr = root;

  // run till stack is not empty or current is not nullptr
  while (!st.empty() || curr != nullptr) {
    // Print left children while exist and keep pushing right into the stack.
    while (curr != nullptr) {
      cout << curr->data << " ";
      if (curr->right) st.push(curr->right);
      curr = curr->left;
    }
    // We reach when curr is nullptr, so We take out a right child from stack
    if (st.empty() == false) {
      curr = st.top();
      st.pop();
    }
  }
}

// Method 2 :- 
// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(Node* root) {
  if (!root) return;
  stack<Node*> nodeStack;
  nodeStack.push(root);

  /* Pop all items one by one. Do following for every popped item
     a) print it
     b) push its right child
     c) push its left child
  Note that right child is pushed first so that left is processed first */
  while (nodeStack.empty() == false) {
    // Pop the top item from stack and print it
    Node* node = nodeStack.top();
    printf("%d ", node->data);
    nodeStack.pop();

    // Push right and left children of the popped node to stack
    if (node->right) nodeStack.push(node->right);
    if (node->left) nodeStack.push(node->left);
  }
}

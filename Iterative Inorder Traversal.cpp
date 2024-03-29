// C++ program to print inorder traversal using stack.
#include<bits/stdc++.h>
using namespace std;
#define nullptr nullptr

struct Node {
  int data;
  struct Node* left, * right;
};

void inOrder(struct Node* root) {
  stack<Node*> s;
  Node* curr = root;
  while (curr != nullptr || s.empty() == false) {
    /* Reach the left most Node of the curr Node */
    while (curr) {
      /* place pointer to a tree node on the stack before traversing the node's left subtree */
      s.push(curr);
      curr = curr->left;
    }
    /* Current must be nullptr at this point */
    curr = s.top();
    s.pop();
    cout << curr->data << " ";
    /* we have visited the node and its left subtree. Now, it's right subtree's turn */
    curr = curr->right;
  }
}
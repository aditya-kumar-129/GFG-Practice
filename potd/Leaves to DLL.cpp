#include <bits/stdc++.h>
using namespace std;
#define nullptr nullptr

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

void inOrder(Node* root) {
  if (!root) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

Node* preorder(Node* root, Node*& prev) {
  if (!root)return nullptr;
  if (!root->right and !root->left) {
    prev->right = root;
    root->left = prev;
    prev = root;
    return nullptr;
  }
  root->left = preorder(root->left, prev);
  root->right = preorder(root->right, prev);
}
Node* convertToDLL(Node* root) {
  // add code here.
  Node* head = new Node(0), * prev = head;
  preorder(root, prev);
  head->right->left = nullptr;
  return head->right;
}
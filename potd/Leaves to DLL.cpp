#include <bits/stdc++.h>
using namespace std;
#define nullptr nullptr

struct Node {
  int data;
  Node* left, * right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

Node* preorder(Node* root, Node*& prev) {
  if (!root) return nullptr;
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
  Node* head = new Node(0), * prev = head;
  preorder(root, prev);
  head->right->left = nullptr;
  return head->right;
}
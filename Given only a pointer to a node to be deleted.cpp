#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
} *head;

Node* findNode(Node* head, int search_for) {
  Node* current = head;
  while (current) {
    if (current->data == search_for) break;
    current = current->next;
  }
  return current;
}

class Solution {
public:
  void deleteNode(Node* node_ptr) {
    // deleting the last node
    if (node_ptr->next == nullptr) {
      free(node_ptr);
      return;
    }
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
  }
};

// Same method:- 

void deleteNode(Node* del) {
  del->data = del->next->data;
  del->next = (del->next)->next;
}
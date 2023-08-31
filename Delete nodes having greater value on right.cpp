#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

class Solution {
public:
  Node* reverse(Node* head) {
    Node* next = nullptr, * curr = head, * prev = nullptr;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return head;
  }
  Node* compute(Node* head) {
    head = reverse(head);
    struct Node* current = head, * maxnode = head, * temp;
    while (current != nullptr && current->next != nullptr) {
      if (current->next->data < maxnode->data) {
        temp = current->next;
        current->next = temp->next;
        free(temp);
      }
      else {
        current = current->next;
        maxnode = current;
      }
    }
    head = reverse(head);
    return head;
  }
};
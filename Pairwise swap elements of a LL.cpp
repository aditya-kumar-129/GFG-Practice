#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  Node* pairWiseSwap(struct Node* head) {
    if (!head || !head->next) return head;
    Node* prev = head, * curr = head->next;
    head = curr;
    while (true) {
      Node* temp = curr->next;
      curr->next = prev;
      if (!temp || !temp->next) {
        prev->next = temp;
        break;
      }
      prev->next = temp->next;
      prev = temp;
      curr = prev->next;
    }
    return head;
  }
};
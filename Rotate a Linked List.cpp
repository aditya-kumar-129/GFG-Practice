#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  Node* rotate(Node* head, int k) {
    if (k == 0) return nullptr;
    Node* current = head;
    int count = 1;
    while (count < k && current != nullptr) {
      current = current->next;
      count++;
    }
    if (!current) return nullptr;
    Node* kthNode = current;
    while (current->next) current = current->next;
    current->next = head;
    head = kthNode->next;
    kthNode->next = nullptr;
    return head;
  }
};
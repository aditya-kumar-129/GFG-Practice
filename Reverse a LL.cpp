#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  struct Node* reverseList(struct Node* head) {
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
    return head;
  }
};
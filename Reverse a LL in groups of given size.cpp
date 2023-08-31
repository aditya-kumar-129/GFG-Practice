#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  struct Node* reverse(struct Node* head, int k) {
    if (!head) return nullptr;
    Node* current = head, * next = nullptr, * prev = nullptr;
    int count = 0;
    while (current != nullptr && count < k) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
      count++;
    }
    if (next) head->next = reverse(next, k);
    return prev;
  }
};
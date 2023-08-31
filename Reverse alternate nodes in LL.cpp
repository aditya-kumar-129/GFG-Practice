#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  Node* reverse(Node* head) {
    Node* curr = head, * prev = nullptr, * next;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  void rearrange(struct Node* head) {
    Node* odd = head;
    Node* odd_start = odd;
    Node* even = head->next;
    Node* evenstart = even;
    while (odd->next && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    Node* reverse_temp = reverse(evenstart);
    odd->next = reverse_temp;
    head = odd_start;
  }
};
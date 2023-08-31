#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  void rearrangeEvenOdd(Node* head) {
    if (!head) return;
    Node* odd = head, * even = head->next, * evenstart = even;
    while (odd->next && even->next) {
      odd->next = even->next;
      odd = even->next;
      even->next = odd->next;
      even = odd->next;
    }
    odd->next = evenstart;
    if (even) even->next = nullptr;
  }
};
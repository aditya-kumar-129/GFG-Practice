#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

class Solution {
public:
  void linkdelete(struct Node* head, int M, int N) {
    Node* curr = head, * t;
    int count;
    while (curr) {
      for (count = 1; count < M && curr != nullptr; count++)
        curr = curr->next;
      if (curr == nullptr)
        return;
      t = curr->next;
      for (count = 1; count <= N && t != nullptr; count++) {
        Node* temp = t;
        t = t->next;
        free(temp);
      }
      curr->next = t;
      curr = t;
    }
  }
};
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

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
  set<int> s;
  while (head1) {
    s.insert(head1->data);
    head1 = head1->next;
  }
  while (head2) {
    s.insert(head2->data);
    head2 = head2->next;
  }
  Node* temp = nullptr, * tail = nullptr;
  for (auto it : s) {
    Node* newnode = new Node(it);
    if (temp == nullptr) {
      temp = newnode;
      tail = temp;
    }
    else {
      tail->next = newnode;
      tail = tail->next;
    }
  }
  return temp;
}
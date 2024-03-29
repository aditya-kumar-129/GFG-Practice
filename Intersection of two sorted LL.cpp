#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = nullptr;
  }
};

Node* findIntersection(Node* head1, Node* head2) {
  map<int, int> m;
  Node* temp1 = head1, * temp2 = head2;
  while (temp1) {
    m[temp1->data]++;
    temp1 = temp1->next;
  }
  while (temp2) {
    m[temp2->data]++;
    temp2 = temp2->next;
  }
  Node* head3 = new Node(-1);
  Node* temp3 = head3;
  for (auto it : m) {
    if (it.second >= 2) {
      Node* n1 = new Node(it.first);
      temp3->next = n1;
      temp3 = n1;
    }
  }
  head3 = head3->next;
  return head3;
}
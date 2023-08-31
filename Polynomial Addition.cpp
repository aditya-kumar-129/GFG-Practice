#include <bits/stdc++.h>
using namespace std;

struct Node {
  int coeff;
  int pow;
  struct Node* next;
  Node(int c, int p) {
    coeff = c;
    pow = p;
    next = nullptr;
  }
};

void append(struct Node** head_ref, struct Node** tail_ref, int new_data, int new_data1) {
  struct Node* new_node = new Node(new_data, new_data1);
  if (!*head_ref) *head_ref = new_node;
  else (*tail_ref)->next = new_node;
  *tail_ref = new_node;
}

class Solution {
public:
  Node* addPolynomial(Node* p1, Node* p2) {
    Node* ptr1 = p1, * ptr2 = p2;
    Node* dummy = new Node(-1, -1);
    Node* ptr3 = dummy;
    while (ptr1 && ptr2) {
      if (ptr1->pow > ptr2->pow) {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
      }
      else if (ptr1->pow < ptr2->pow) {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
      }
      else {
        ptr1->coeff = ptr1->coeff + ptr2->coeff;
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      }
      ptr3 = ptr3->next;
    }
    while (ptr1) {
      ptr3->next = ptr1;
      ptr1 = ptr1->next;
      ptr3 = ptr3->next;
    }
    while (ptr2) {
      ptr3->next = ptr2;
      ptr2 = ptr2->next;
      ptr3 = ptr3->next;
    }
    return dummy->next;
  }
};
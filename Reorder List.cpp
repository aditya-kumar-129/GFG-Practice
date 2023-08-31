#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

void freeList(struct Node* head) {
  struct Node* temp;
  while (head) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

Node* reverse(Node* head) {
  Node* curr = head;
  Node* prev = nullptr, * next;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void reorderList(Node* root) {
  Node* slow = root, * fast = root, * head1 = root;
  Node* head2;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  head2 = slow->next;
  slow->next = nullptr;
  head2 = reverse(head2);

  Node* tmp = head1;
  head1 = head1->next;
  while (head2) {
    tmp->next = head2;
    head2 = head2->next;
    tmp = tmp->next;
    tmp->next = head1;
    head1 = head1->next;
    tmp = tmp->next;
  }
}
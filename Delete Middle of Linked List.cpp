#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
};

Node* deleteMid(Node* head)
{
  if (!head || !head->next) return nullptr;
  Node* slow = head, * fast = head, * temp = nullptr;
  while (fast && fast->next) {
    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  temp->next = slow->next;
  free(slow);
  return head;
}
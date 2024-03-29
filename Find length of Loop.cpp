#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void loopHere(Node* head, Node* tail, int position) {
  if (position == 0) return;
  Node* walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

int countNodesinLoop(struct Node* head) {
  int flag = 0;
  Node* fast = head, * slow = head;
  while (fast && slow && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      flag = 1;
      break;
    }
  }
  // in case when there is loop return the length of the loop
  if (flag) {
    Node* temp = slow;
    int count = 1;
    while (temp->next != slow) {
      count++;
      temp = temp->next;
    }
    return count;
  }
  // if their is no loop in the linked list then in that case return 0
  else return 0;
}
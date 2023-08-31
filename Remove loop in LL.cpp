#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

//Loop is being created using the below function
void loopHere(Node* head, Node* tail, int position) {
  if (position == 0) return;
  Node* walk = head;
  for (int i = 1; i < position; i++) walk = walk->next;
  tail->next = walk;
}

// Checking if any loop exist or not
bool isLoop(Node* head) {
  if (!head) return false;
  Node* fast = head->next;
  Node* slow = head;
  while (fast != slow) {
    if (!fast || !fast->next) return false;
    fast = fast->next->next;
    slow = slow->next;
  }
  return true;
}

// This function is used to calculate the length of the linked list so as to compare whether loop is removed or not
int length(Node* head) {
  int len = 0;
  while (head) {
    len++;
    head = head->next;
  }
  return len;
}
/*
  See the below youtube video to understand the logic behind the solution of the problem
  https://www.youtube.com/watch?v=jcZtMh_jov0
*/
class Solution {
public:
  Node* detectLoopNode(Node* head) {
    Node* slow = head, * fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      // Loop detected
      if (slow == fast) {
        slow = head;
        // In this case even if the slow and fast pointer points to the head of the LL then also the while used in the removeloop() will handle this case also
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return fast;  // first looping Node;
      }
    }
    return nullptr;
  }

  void removeLoop(Node* head) {
    Node* loopNode = detectLoopNode(head);
    // There is no loop
    if (!loopNode) return;
    Node* temp = loopNode->next;
    while (temp->next != loopNode) temp = temp->next;
    temp->next = nullptr;
    return;
  }
};
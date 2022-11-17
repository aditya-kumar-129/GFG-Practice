#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

struct Node* deleteMid(struct Node* head);
void printList(Node* node)
{
  while (node != nullptr)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

Node* deleteMid(Node* head)
{
  if (head == nullptr || head->next == nullptr)
    return nullptr;
  Node* slow = head;
  Node* fast = head;
  Node* temp = nullptr;
  while (fast != nullptr && fast->next != nullptr)
  {
    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  temp->next = slow->next;
  free(slow);
  return head;
}
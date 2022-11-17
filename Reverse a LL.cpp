#include <iostream>
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

class Solution
{
public:
  struct Node* reverseList(struct Node* head)
  {
    Node* current = head;
    Node* prev = nullptr, * next = nullptr;
    while (current != nullptr)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
    return head;
  }
};

void printList(struct Node* head)
{
  struct Node* temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
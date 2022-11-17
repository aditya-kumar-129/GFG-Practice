#include<iostream>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
  Node(int x)
  {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};

class Solution
{
public:
  Node* deleteNode(Node* head, int x)
  {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
    {
      delete head;
      return nullptr;
    }
    Node* curr = head;
    if (x == 1)
    {
      curr->next->prev = nullptr;
      head = curr->next;
      curr->next = nullptr;
      delete curr;
      return head;
    }
    while (x != 1)
    {
      curr = curr->next;
      x--;
    }
    curr->prev->next = curr->next;
    if (curr->next != nullptr)
      curr->next->prev = curr->prev;

    delete curr;
    return head;
  }
};

void printList(struct Node* node)
{
  while (node != nullptr)
  {
    cout << node->data;
    node = node->next;
  }
  printf("\n");
}
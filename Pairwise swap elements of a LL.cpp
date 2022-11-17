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

class Solution
{
public:
  Node* pairWiseSwap(struct Node* head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    Node* prev = head;
    Node* curr = head->next;
    head = curr;
    while (true)
    {
      Node* temp = curr->next;
      curr->next = prev;
      if (temp == nullptr || temp->next == nullptr)
      {
        prev->next = temp;
        break;
      }
      prev->next = temp->next;
      prev = temp;
      curr = prev->next;
    }
    return head;
  }
};

void printList(Node* Node)
{
  while (Node != nullptr)
  {
    cout << Node->data << " ";
    Node = Node->next;
  }
  cout << "\n";
}
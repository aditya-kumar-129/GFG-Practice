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
  //Function to rotate a linked list
  Node* rotate(Node* head, int k)
  {
    if (k == 0)
      return nullptr;
    Node* current = head;
    int count = 1;
    while (count < k && current != nullptr)
    {
      current = current->next;
      count++;
    }
    if (current == nullptr)
      return nullptr;
    Node* kthNode = current;
    while (current->next != nullptr)
      current = current->next;
    current->next = head;
    head = kthNode->next;
    kthNode->next = nullptr;
    return head;
  }
};

void printList(Node* n)
{
  while (n != nullptr)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}
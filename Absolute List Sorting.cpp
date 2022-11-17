#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node* next;
  int data;
};

void push(Node** head, int data)
{
  Node* newNode = new Node;
  newNode->next = (*head);
  newNode->data = data;
  (*head) = newNode;
}

void printList(Node* head)
{
  while (head != nullptr)
  {
    cout << head->data;
    if (head->next != nullptr)
      cout << " ";
    head = head->next;
  }
  cout << endl;
}

class Solution
{
public:
  void sortList(Node** head)
  {
    Node* prev = (*head);
    Node* curr = (*head)->next;
    while (curr != nullptr)
    {
      if (curr->data < prev->data)
      {
        prev->next = curr->next;
        curr->next = (*head);
        (*head) = curr;
        curr = prev;
      }
      else
        prev = curr;
      curr = curr->next;
    }
  }
};
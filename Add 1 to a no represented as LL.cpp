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

void printList(Node* node)
{
  while (node != nullptr)
  {
    cout << node->data;
    node = node->next;
  }
  cout << "\n";
}

class Solution
{
public:
  Node* reverse(Node* head)
  {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;
    while (current != nullptr)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
  Node* addOne(Node* head)
  {
    head = reverse(head);
    Node* res = head;
    Node* temp;
    int carry = 1, sum;
    while (head != nullptr)
    {
      sum = carry + head->data;
      carry = (sum == 10) ? 1 : 0;
      sum = sum % 10;
      head->data = sum;
      temp = head;
      head = head->next;
    }
    if (carry > 0)
      temp->next = new Node(carry);
    res = reverse(res);
    return res;
  }
};
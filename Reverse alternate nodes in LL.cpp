#include <stdio.h>
#include <stdlib.h>
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

struct Node* start = nullptr;

void printList(struct Node* node)
{
  while (node != nullptr)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void insert()
{
  int n, value;
  cin >> n;
  struct Node* temp;
  for (int i = 0; i < n; i++)
  {
    cin >> value;
    if (i == 0)
    {
      start = new Node(value);
      temp = start;
      continue;
    }
    else
    {
      temp->next = new Node(value);
      temp = temp->next;
    }
  }
}

class Solution
{
public:
  Node* reverse(Node* head)
  {
    Node* cur = head, * prev = nullptr, * next;
    while (cur != nullptr)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
  void rearrange(struct Node* head)
  {
    Node* odd = head;
    Node* odd_start = odd;
    Node* even = head->next;
    Node* evenstart = even;
    while (odd->next != nullptr && even->next != nullptr)
    {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    Node* reverse_temp = reverse(evenstart);
    odd->next = reverse_temp;
    head = odd_start;
  }
};
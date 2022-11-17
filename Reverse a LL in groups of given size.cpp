#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node* next;
  node(int x)
  {
    data = x;
    next = nullptr;
  }
};

void printList(struct node* node)
{
  while (node != nullptr)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

class Solution
{
public:
  struct node* reverse(struct node* head, int k)
  {
    if (!head)
      return nullptr;
    node* current = head;
    node* next = nullptr;
    node* prev = nullptr;
    int count = 0;
    while (current != nullptr && count < k)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
      count++;
    }
    if (next != nullptr)
      head->next = reverse(next, k);
    return prev;
  }
};
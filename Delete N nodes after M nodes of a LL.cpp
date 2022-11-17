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

void insert(int n1)
{
  int n, value;
  n = n1;
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
  void linkdelete(struct Node* head, int M, int N)
  {
    Node* curr = head, * t;
    int count;
    while (curr)
    {
      for (count = 1; count < M && curr != nullptr; count++)
        curr = curr->next;
      if (curr == nullptr)
        return;
      t = curr->next;
      for (count = 1; count <= N && t != nullptr; count++)
      {
        Node* temp = t;
        t = t->next;
        free(temp);
      }
      curr->next = t;
      curr = t;
    }
  }
};

int main()
{
  int t, n1;
  cin >> t;
  while (t--)
  {
    cin >> n1;
    int m, n;
    cin >> m >> n;
    insert(n1);
    Solution ob;
    ob.linkdelete(start, m, n);
    printList(start);
  }
  return 0;
}
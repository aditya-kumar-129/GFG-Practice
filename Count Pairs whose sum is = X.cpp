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

void append(struct Node** headRef, struct Node** tailRef, int newData)
{
  struct Node* new_node = new Node(newData);
  if (*headRef == nullptr)
    *headRef = new_node;
  else
    (*tailRef)->next = new_node;
  *tailRef = new_node;
}

void printList(struct Node* head)
{
  while (head)
  {
    cout << head->data << ' ';
    head = head->next;
  }
}

class Solution
{
public:
  int countPairs(struct Node* head1, struct Node* head2, int x)
  {
    set<int> s1, s2;
    Node* temp1 = head1;
    while (temp1 != nullptr)
    {
      s1.insert(temp1->data);
      temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while (temp2 != nullptr)
    {
      s2.insert(temp2->data);
      temp2 = temp2->next;
    }
    int count = 0;
    for (auto it : s1)
    {
      int rem = x - it;
      if (s2.find(rem) != s2.end())
        count++;
    }
    return count;
  }
};
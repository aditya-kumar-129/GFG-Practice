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

struct Node* buildList(int size)
{
  int val;
  cin >> val;
  Node* head = new Node(val);
  Node* tail = head;
  for (int i = 0; i < size - 1; i++)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }
  return head;
}

void printList(Node* n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
  set<int> s;
  while (head1)
  {
    s.insert(head1->data);
    head1 = head1->next;
  }
  while (head2)
  {
    s.insert(head2->data);
    head2 = head2->next;
  }
  Node* temp = nullptr;
  Node* tail = nullptr;
  for (auto it : s)
  {
    Node* newnode = new Node(it);
    if (temp == nullptr)
    {
      temp = newnode;
      tail = temp;
    }
    else
    {
      tail->next = newnode;
      tail = tail->next;
    }
  }
  return temp;
}

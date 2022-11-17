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

Node* sortedMerge(struct Node* a, struct Node* b);
void printList(struct Node* n)
{
  while (n != nullptr)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

Node* sortedMerge(Node* head1, Node* head2)
{
  if (head1 == nullptr)
    return head2;
  else if (head2 == nullptr)
    return head1;

  Node* mergedHead = nullptr;
  if (head1->data <= head2->data)
  {
    mergedHead = head1;
    head1 = head1->next;
  }
  else
  {
    mergedHead = head2;
    head2 = head2->next;
  }
  Node* mergedTail = mergedHead;
  while (head1 != nullptr && head2 != nullptr)
  {
    Node* temp = nullptr;
    if (head1->data <= head2->data)
    {
      temp = head1;
      head1 = head1->next;
    }
    else
    {
      temp = head2;
      head2 = head2->next;
    }
    mergedTail->next = temp;
    mergedTail = temp;
  }
  if (head1 != nullptr)
    mergedTail->next = head1;
  else if (head2 != nullptr)
    mergedTail->next = head2;
  return mergedHead;
}
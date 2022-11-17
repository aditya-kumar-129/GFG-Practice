// HAVE A LOOK ON SPILITING OF THE LINKED LIST OF THE VARIOUS METHOD. THE CODES ARE LITTILE DIFFERENT BUT WORKS SAME.
// ALSO AS MUCH AS I GET IN CASE OF A LINKED LIST WE SPILIT THE LIST WITH THE ASSUMPTION THAT IF WE ASSUME IT TO BE AS ARRAY THEN IT SPILT WITH INDEX 1. 
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* next, * prev;
  Node(int x)
  {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};

Node* merge(Node* first, Node* second)
{
  if (first == nullptr)
    return second;
  if (second == nullptr)
    return first;
  if (first->data < second->data)
  {
    first->next = merge(first->next, second);
    first->next->prev = first;
    first->prev = nullptr;
    return first;
  }
  else
  {
    second->next = merge(first, second->next);
    second->next->prev = second;
    second->prev = nullptr;
    return second;
  }
}

struct Node* split(Node* head)
{
  Node* slow = head;
  Node* fast = head;
  while (fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct Node* temp = slow->next;
  slow->next = nullptr;
  temp->prev = nullptr;
  return temp;
}

struct Node* sortDoubly(Node* head)
{
  if (!head || !head->next)
    return head;
  Node* head2 = split(head);
  head = sortDoubly(head);
  head2 = sortDoubly(head2);
  return merge(head, head2);
}

void insert(struct Node** head, int data)
{
  struct Node* temp = new Node(data);
  if (!(*head))
    (*head) = temp;
  else
  {
    temp->next = *head;
    (*head)->prev = temp;
    (*head) = temp;
  }
}

void print(struct Node* head)
{
  struct Node* temp = head;
  while (head)
  {
    cout << head->data << ' ';
    temp = head;
    head = head->next;
  }
  cout << endl;
  while (temp)
  {
    cout << temp->data << ' ';
    temp = temp->prev;
  }
  cout << endl;
}

void swap(int* A, int* B)
{
  int temp = *A;
  *A = *B;
  *B = temp;
}

// method 2:-  ITERATIVE METHOD
Node* merge(Node* head1, Node* head2)
{
  Node* dummy = new Node(0);
  Node* temp = dummy;
  while (head1 && head2)
  {
    if (head1->data <= head2->data)
    {
      temp->next = head1;
      head1->prev = temp;
      head1 = head1->next;
    }
    else
    {
      temp->next = head2;
      head2->prev = temp;
      head2 = head2->next;
    }
    temp = temp->next;
  }
  if (head1)
  {
    temp->next = head1;
    head1->prev = temp;
  }
  else if (head2)
  {
    temp->next = head2;
    head2->prev = temp;
  }
  temp = dummy->next;
  temp->prev = nullptr;
  return temp;
}

struct Node* sortDoubly(struct Node* head)
{
  if (head == nullptr || head->next == nullptr)
    return head;
  Node* slow = head, * fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->prev->next = nullptr;
  slow->prev = nullptr;
  head = sortDoubly(head);
  slow = sortDoubly(slow);
  return merge(head, slow);
}

// method 2:-  RECURSIVE METHOD
Node* merge(Node* first, Node* second)
{
  if (!first)
    return second;
  if (!second)
    return first;
  if (first->data > second->data)
    return merge(second, first);
  Node* ans = merge(first->next, second);
  first->next = ans;
  ans->prev = first;
  return first;
}

struct Node* sortDoubly(struct Node* head)
{
  if (!head || !head->next)
    return head;
  Node* slow = head, * fast = head, * prev = head;
  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;
  slow->prev = nullptr;
  Node* first = sortDoubly(head);
  Node* second = sortDoubly(slow);
  head = merge(first, second);
  return head;
}

// Method 3:- When you want to use space
struct Node* sortDoubly(struct Node* head)
{
  vector<int> v;
  Node* temp = head;
  while (temp != nullptr)
  {
    v.push_back(temp->data);
    temp = temp->next;
  }
  sort(v.begin(), v.end());
  Node* Dummy = new Node(v[0]);
  Node* temp1 = Dummy;
  for (int i = 1; i < v.size(); i++)
  {
    temp1->next = new Node(v[i]);
    Node* sa = temp1;
    temp1 = temp1->next;
    temp1->prev = sa;
  }
  return Dummy;
}
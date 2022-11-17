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

struct Node* start = nullptr;

class Solution
{
public:
  // This is what I have done to solve this problem 
  /*
  First i have counted the total number of 0's, 1's and 2's present in the linked list
  then i just modified the the Node->data
  */

  //  Brute force approach
  Node* segregate(Node* head)
  {
    int count[3] = { 0, 0, 0 };
    Node* temp = head;
    while (temp != nullptr)
    {
      count[temp->data] += 1;
      temp = temp->next;
    }
    int i = 0;
    temp = head;
    while (temp != nullptr)
    {
      if (count[i] == 0)
        ++i;
      else
      {
        temp->data = i;
        --count[i];
        temp = temp->next;
      }
    }
    return head;
  }
};

void printList(struct Node* Node)
{
  while (Node != nullptr)
  {
    printf("%d ", Node->data);
    Node = Node->next;
  }
  printf("\n");
}

void insert(int n1)
{
  int n, value, i;
  n = n1;
  struct Node* temp;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &value);
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
      temp->next = nullptr;
    }
  }
}

// Method 2:
// OPTIMISED SOLUTION
// TIME COMPLEXITY:- O(n)
// SPACE COMPLEXITY:- O(1)

class Solution
{
public:
  Node* segregate(Node* head)
  {
    if (!head || !(head->next))
      return head;

    // Create three dummy nodes to point to beginning of three linked lists. These dummy nodes are created to avoid many null checks.
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);

    // Initialize current pointers for three lists and whole list.
    Node* zero = zeroD, * one = oneD, * two = twoD;

    // Traverse list
    Node* curr = head;
    while (curr)
    {
      if (curr->data == 0)
      {
        zero->next = curr;
        zero = zero->next;
        curr = curr->next;
      }
      else if (curr->data == 1)
      {
        one->next = curr;
        one = one->next;
        curr = curr->next;
      }
      else
      {
        two->next = curr;
        two = two->next;
        curr = curr->next;
      }
    }

    // Attach three lists
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = nullptr;
    // Updated head
    head = zeroD->next;
    // Delete dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
  }
};
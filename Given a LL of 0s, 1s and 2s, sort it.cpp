#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

struct Node *start = NULL;

class Solution
{
public:
  // This is what I have done to solve this problem 
  /*
  First i have counted the total number of 0 1 and 2 present in the linked list 
  then i just modified the the Node->data 
  */
  Node *segregate(Node *head)
  {
    int count[3] = {0, 0, 0};
    Node *temp = head;
    while (temp != NULL)
    {
      count[temp->data] += 1;
      temp = temp->next;
    }
    int i = 0;
    temp = head;
    while (temp != NULL)
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

void printList(struct Node *Node)
{
  while (Node != NULL)
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
  struct Node *temp;
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
      temp->next = NULL;
    }
  }
}

int main()
{
  int n;
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);

    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);
  }
  return 0;
}
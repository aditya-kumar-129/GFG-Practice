#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};

void printList(struct node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

class Solution
{
public:
  struct node *reverse(struct node *head, int k)
  {
    if (!head)
      return NULL;
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
      count++;
    }
    if (next != NULL)
      head->next = reverse(next, k);
    return prev;
  }
};

int main(void)
{
  int t;
  cin >> t;
  while (t--)
  {
    struct node *head = NULL;
    struct node *temp = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int value;
      cin >> value;
      if (i == 0)
      {
        head = new node(value);
        temp = head;
      }
      else
      {
        temp->next = new node(value);
        temp = temp->next;
      }
    }
    int k;
    cin >> k;
    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
  }
  return (0);
}
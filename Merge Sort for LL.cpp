#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
  Node *merge(Node *first, Node *second)
  {
    Node *node, *temp;
    if (first->data > second->data)
      node = second, second = second->next;
    else
      node = first, first = first->next;
    temp = node;
    while (first != NULL && second != NULL)
    {
      if (first->data > second->data)
        node->next = second, second = second->next;
      else
        node->next = first, first = first->next;
      node = node->next;
    }
    while (second != NULL)
    {
      node->next = second;
      node = node->next;
      second = second->next;
    }
    while (first != NULL)
    {
      node->next = first;
      node = node->next;
      first = first->next;
    }
    return temp;
  }

  Node *middle(Node *head)
  {
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    return fast;
  }

  Node *mergeSort(Node *head)
  {
    // if there is no element or only one element then in that case just return the head
    if (head == NULL || head->next == NULL)
      return head;
    // In case when there are only two elements present in the LL
    if (head->next->next == NULL)
    {
      Node *fast = head->next;
      head->next = NULL;
      return merge(head, fast);
    }
    Node * head2 = middle(head);
    return merge(mergeSort(head), mergeSort(head2));
  }
};

void printList(Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
  Node *new_node = new Node(new_data);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main()
{
  long test;
  cin >> test;
  while (test--)
  {
    struct Node *a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> tmp;
      push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
  }
  return 0;
}
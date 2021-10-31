#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
  Node *merge(Node *firstNode, Node *secondNode)
  {
    Node *merged = (struct Node *)malloc(sizeof(struct Node));
    Node *temp = (struct Node *)malloc(sizeof(struct Node));

    //merged is equal to temp so in the end we have the top Node.
    merged = temp;

    //while either firstNode or secondNode becomes NULL
    while (firstNode != NULL && secondNode != NULL)
    {

      if (firstNode->data <= secondNode->data)
      {
        temp->next = firstNode;
        firstNode = firstNode->next;
      }

      else
      {
        temp->next = secondNode;
        secondNode = secondNode->next;
      }
      temp = temp->next;
    }

    //any remaining Node in firstNode or secondNode gets inserted in the temp List
    while (firstNode != NULL)
    {
      temp->next = firstNode;
      firstNode = firstNode->next;
      temp = temp->next;
    }

    while (secondNode != NULL)
    {
      temp->next = secondNode;
      secondNode = secondNode->next;
      temp = temp->next;
    }
    //return the head of the sorted list
    return merged->next;
  }
  Node *middle(Node *head)
  {
    Node *slow = head;
    Node *fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL))
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  Node *mergeSort(Node *head)
  {
    if (head->next == NULL)
    {
      return head;
    }

    Node *mid = (struct Node *)malloc(sizeof(struct Node));
    ;
    Node *head2 = (struct Node *)malloc(sizeof(struct Node));
    ;
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL;
    //recursive call to sort() hence diving our problem, and then merging the solution
    Node *finalhead = merge(mergeSort(head), mergeSort(head2));
    return finalhead;
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
} // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *next;
  int data;
};

void push(Node **head, int data)
{
  Node *newNode = new Node;
  newNode->next = (*head);
  newNode->data = data;
  (*head) = newNode;
}

void printList(Node *head)
{
  while (head != NULL)
  {
    cout << head->data;
    if (head->next != NULL)
      cout << " ";
    head = head->next;
  }
  cout << endl;
}

class Solution
{
public:
  void sortList(Node **head)
  {
    Node *prev = (*head);
    Node *curr = (*head)->next;
    while (curr != NULL)
    {
      if (curr->data < prev->data)
      {
        prev->next = curr->next;
        curr->next = (*head);
        (*head) = curr;
        curr = prev;
      }
      else
        prev = curr;
      curr = curr->next;
    }
  }
};

int main()
{
  int t = 0;
  int n = 0;
  cin >> t;
  while (t--)
  {
    Node *head = NULL;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
      push(&head, arr[i]);
    Solution ob;
    ob.sortList(&head);
    printList(head);
  }
  return 0;
}
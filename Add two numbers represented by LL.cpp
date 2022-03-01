/*
  You can refer the below article for more explanation:-
  https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
*/
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

struct Node *buildList(int size)
{
  int val;
  cin >> val;
  Node *head = new Node(val);
  Node *tail = head;
  for (int i = 0; i < size - 1; i++)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }
  return head;
}

void printList(Node *n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

class Solution
{
public:
  Node *reverse(Node *head)
  {
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }

  struct Node *addTwoLists(struct Node *first, struct Node *second)
  {
    first = reverse(first);
    second = reverse(second);
    Node *res = NULL, *temp;
    int carry = 0, newval;
    while (first != NULL || second != NULL || carry != 0)
    {
      newval = carry;
      if (first)
        newval += first->data;
      if (second)
        newval += second->data;
      carry = newval / 10;
      newval = newval % 10;
      Node *newNode = new Node(newval);
      if (!res)
        res = newNode, temp = newNode;
      else
        temp->next = newNode, temp = temp->next;
      if (first)
        first = first->next;
      if (second)
        second = second->next;
    }
    res = reverse(res);
    return res;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    // n and m are number of digits present in the two numbers.
    int n, m;
    cin >> n;
    Node *first = buildList(n);
    cin >> m;
    Node *second = buildList(m);
    Solution ob;
    Node *res = ob.addTwoLists(first, second);
    printList(res);
  }
  return 0;
}
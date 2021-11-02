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

struct Node *makeUnion(struct Node *head1, struct Node *head2);

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n;
    Node *first = buildList(n);
    cin >> m;
    Node *second = buildList(m);
    printList(makeUnion(first, second));
  }
  return 0;
}

struct Node *makeUnion(struct Node *head1, struct Node *head2)
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
  Node *temp = NULL;
  Node *tail = NULL;
  for (auto it : s)
  {
    Node *newnode = new Node(it);
    if (temp == NULL)
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

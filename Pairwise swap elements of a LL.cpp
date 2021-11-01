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
  Node *pairWiseSwap(struct Node *head)
  {
    if (head == NULL || head->next == NULL)
      return head;
    Node *prev = head;
    Node *curr = head->next;
    head = curr;
    while (true)
    {
      Node *temp = curr->next;
      curr->next = prev;
      if (temp == NULL || temp->next == NULL)
      {
        prev->next = temp;
        break;
      }
      prev->next = temp->next;
      prev = temp;
      curr = prev->next;
    }
    return head;
  }
};

void printList(Node *Node)
{
  while (Node != NULL)
  {
    cout << Node->data << " ";
    Node = Node->next;
  }
  cout << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    map<Node *, int> mp;
    mp[head] = head->data;
    for (int i = 0; i < n - 1; ++i)
    {
      cin >> data;
      tail->next = new Node(data);
      tail = tail->next;
      mp[tail] = tail->data;
    }
    struct Node *failure = new Node(-1);
    Solution ob;
    head = ob.pairWiseSwap(head);
    int flag = 0;
    struct Node *temp = head;
    while (temp)
    {
      if (mp[temp] != temp->data)
      {
        flag = 1;
        break;
      }
      temp = temp->next;
    }
    if (flag)
      printList(failure);
    else
      printList(head);
  }
  return 0;
}
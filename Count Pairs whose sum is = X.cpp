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

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
  struct Node *new_node = new Node(newData);
  if (*headRef == NULL)
    *headRef = new_node;
  else
    (*tailRef)->next = new_node;
  *tailRef = new_node;
}

void printList(struct Node *head)
{
  while (head)
  {
    cout << head->data << ' ';
    head = head->next;
  }
}

class Solution
{
public:
  int countPairs(struct Node *head1, struct Node *head2, int x)
  {
    set<int> s1, s2;
    Node *temp1 = head1;
    while (temp1 != NULL)
    {
      s1.insert(temp1->data);
      temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2 != NULL)
    {
      s2.insert(temp2->data);
      temp2 = temp2->next;
    }
    int count = 0;
    for (auto it : s1)
    {
      int rem = x - it;
      if (s2.find(rem) != s2.end())
        count++;
    }
    return count;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    struct Node *head1,*head2,*tail2,*tail1 = NULL;
    int n1, n2, tmp, x;
    cin >> n1;
    while (n1--)
    {
      cin >> tmp;
      append(&head1, &tail1, tmp);
    }
    cin >> n2;
    while (n2--)
    {
      cin >> tmp;
      append(&head2, &tail2, tmp);
    }
    cin >> x;
    Solution obj;
    cout << obj.countPairs(head1, head2, x) << '\n';
  }
  return 0;
}
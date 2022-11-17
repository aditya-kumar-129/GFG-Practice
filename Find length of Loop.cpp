#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

void loopHere(Node* head, Node* tail, int position)
{
  if (position == 0)
    return;
  Node* walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

int countNodesinLoop(Node* head);
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, num;
    cin >> n;
    Node* head, * tail;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 0; i < n - 1; i++)
    {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }
    int pos;
    cin >> pos;
    loopHere(head, tail, pos);
    cout << countNodesinLoop(head) << endl;
  }
  return 0;
}

int countNodesinLoop(struct Node* head)
{
  int flag = 0;
  Node* fast = head;
  Node* slow = head;
  while (fast && slow && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      flag = 1;
      break;
    }
  }
  if (flag) // in case when there is loop return the length of the loop
  {
    Node* temp = slow;
    int count = 1;
    while (temp->next != slow)
    {
      count++;
      temp = temp->next;
    }
    return count;
  }
  else // if their is no loop in the linked list then in that case return 0
    return 0;
}
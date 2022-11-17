#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

class Solution
{
public:
  //Function to rotate a linked list
  Node* rotate(Node* head, int k)
  {
    if (k == 0)
      return nullptr;
    Node* current = head;
    int count = 1;
    while (count < k && current != nullptr)
    {
      current = current->next;
      count++;
    }
    if (current == nullptr)
      return nullptr;
    Node* kthNode = current;
    while (current->next != nullptr)
      current = current->next;
    current->next = head;
    head = kthNode->next;
    kthNode->next = nullptr;
    return head;
  }
};

void printList(Node* n)
{
  while (n != nullptr)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, val, k;
    cin >> n;
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;
    for (int i = 0; i < n - 1; i++)
    {
      cin >> val;
      tail->next = new Node(val);
      tail = tail->next;
    }
    cin >> k;
    Solution ob;
    head = ob.rotate(head, k);
    printList(head);
  }
  return 1;
}
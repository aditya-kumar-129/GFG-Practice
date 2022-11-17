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

void printList(Node* node)
{
  while (node != nullptr)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

class Solution
{
public:
  Node* sortedInsert(struct Node* head, int data)
  {
    Node* curr = head->next;
    Node* prev = head;
    Node* new_node = new Node(data);
    if (data < head->data)
    {
      new_node->next = head;
      head = new_node;
      return head;
    }
    while (curr != nullptr)
    {
      if (data < curr->data)
        break;
      prev = prev->next;
      curr = curr->next;
    }
    prev->next = new_node;
    new_node->next = curr;
    return head;
  }
};

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
    struct Node* head = new Node(data);
    struct Node* tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
      cin >> data;
      tail->next = new Node(data);
      tail = tail->next;
    }
    int k;
    cin >> k;
    Solution obj;
    head = obj.sortedInsert(head, k);
    printList(head);
  }
  return 0;
}
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

Node* inputList(int size)
{
  Node* head, * tail;
  int val;
  cin >> val;
  head = tail = new Node(val);
  while (--size)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }
  return head;
}

void printList(Node* n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
}

class Solution
{
public:
  Node* findIntersection(Node* head1, Node* head2)
  {
    Node* head = nullptr, * tail = nullptr;
    Node* temp = head2;
    unordered_map<int, int> mp;
    while (temp != nullptr)
    {
      mp[temp->data]++;
      temp = temp->next;
    }
    temp = head1;
    while (temp != nullptr)
    {
      if (mp.find(temp->data) != mp.end())
      {
        Node* n = new Node(temp->data);
        if (head == nullptr)
        {
          head = n;
          tail = n;
        }
        else
        {
          tail->next = n;
          tail = tail->next;
        }
      }
      temp = temp->next;
    }
    return head;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n;
    Node* head1 = inputList(n);
    cin >> m;
    Node* head2 = inputList(m);
    Solution obj;
    Node* result = obj.findIntersection(head1, head2);
    printList(result);
    cout << endl;
  }
  return 0;
}
#include <iostream>
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
int getNthFromLast(struct Node* head, int n);

int main()
{
  int T, i, n, l, k;
  cin >> T;
  while (T--)
  {
    struct Node* head = nullptr, * tail = nullptr;
    cin >> n >> k;
    int firstdata;
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    cout << getNthFromLast(head, k) << endl;
  }
  return 0;
}

int getNthFromLast(Node* head, int n)
{
  int len = 0, i;
  struct Node* temp = head;
  while (temp != nullptr)
  {
    temp = temp->next;
    len++;
  }
  if (len < n)
    return -1;
  temp = head;
  for (i = 1; i < len - n + 1; i++)
    temp = temp->next;
  return temp->data;
}
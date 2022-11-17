#include <stdlib.h>
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

class Solution
{
public:
  void rearrangeEvenOdd(Node* head)
  {
    if (head == nullptr)
      return;
    Node* odd = head;
    Node* even = head->next;
    Node* evenstart = even;
    while (odd->next != nullptr && even->next != nullptr)
    {
      odd->next = even->next;
      odd = even->next;
      even->next = odd->next;
      even = odd->next;
    }
    odd->next = evenstart;
    if (even)
      even->next = nullptr;
  }
};

int main()
{
  int T, i, n, l;
  cin >> T;
  while (T--)
  {
    struct Node* head = nullptr;
    struct Node* temp = head;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
      cin >> l;
      if (head == nullptr)
        head = temp = new Node(l);
      else
      {
        temp->next = new Node(l);
        temp = temp->next;
      }
    }
    Solution ob;
    ob.rearrangeEvenOdd(head);
    while (head != nullptr)
    {
      printf("%d ", head->data);
      head = head->next;
    }
    printf("\n");
  }
  return 0;
}
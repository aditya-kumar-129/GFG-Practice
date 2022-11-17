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
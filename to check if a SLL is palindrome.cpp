#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node(int d)
  {
    data = d;
  }
  Node* ptr;
};

// Function to check if the linked list is palindrome or not
bool isPalin(Node* head)
{
  Node* slow = head;
  stack<int> s;
  while (slow != nullptr)
  {
    s.push(slow->data);
    slow = slow->ptr;
  }
  // Iterate in the list again and check by popping from the stack
  while (head != nullptr)
  {
    int i = s.top();
    s.pop();
    if (head->data != i)
      return false;
    head = head->ptr;
  }
  return true;
}
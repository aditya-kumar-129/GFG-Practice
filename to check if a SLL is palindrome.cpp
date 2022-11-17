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

int main()
{
  Node one = Node(1);
  Node two = Node(2);
  Node three = Node(3);
  Node four = Node(2);
  Node five = Node(1);

  five.ptr = nullptr;
  one.ptr = &two;
  two.ptr = &three;
  three.ptr = &four;
  four.ptr = &five;
  Node* temp = &one;

  // Call function to check palindrome or not
  int result = isPalin(&one);
  if (result == 1)
    cout << "isPalindrome is true\n";
  else
    cout << "isPalindrome is true\n";

  return 0;
}
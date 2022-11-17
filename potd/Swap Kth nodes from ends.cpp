#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

Node* swapkthnode(Node* head, int num, int K);

void addressstore(Node** arr, Node* head)
{
  Node* temp = head;
  int i = 0;
  while (temp) {
    arr[i] = temp;
    i++;
    temp = temp->next;
  }
}

bool check(Node** before, Node** after, int num, int K)
{
  if (K > num)
    return 1;
  return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

//Function to swap Kth node from beginning and end in a linked list.
Node* swapkthnode(Node* head, int num, int K)
{
  if (K > num) 
    return head;
  Node* first = head, * second = head, * temp;
  Node* fprev = nullptr, * lprev = nullptr;
  for (int i = 0;i < K - 1;i++)
  {
    fprev = first;
    first = first->next;
  }
  for (int i = 0;i < num - K;i++)
  {
    lprev = second;
    second = second->next;
  }
  if (K == 1)
  {
    lprev->next = first;
    second->next = first->next;
    first->next = nullptr;
    return second;
  }
  if (K == num)
  {
    fprev->next = second;
    first->next = second->next;
    second->next = nullptr;
    return first;
  }
  else
  {
    fprev->next = second;
    lprev->next = first;
    temp = first->next;
    first->next = second->next;
    second->next = temp;
    return head;
  }
}
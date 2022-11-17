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
} *head;

Node* findNode(Node* head, int search_for)
{
  Node* current = head;
  while (current != nullptr)
  {
    if (current->data == search_for)
      break;
    current = current->next;
  }
  return current;
}

void insert()
{
  int n, i, value;
  Node* temp;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &value);
    if (i == 0)
    {
      head = new Node(value);
      temp = head;
      continue;
    }
    else
    {
      temp->next = new Node(value);
      temp = temp->next;
      temp->next = nullptr;
    }
  }
}

void printList(Node* node)
{
  while (node != nullptr)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

class Solution
{
public:
  void deleteNode(Node* node_ptr)
  {
    if (node_ptr->next == nullptr)  // deleting the last node
    {
      free(node_ptr);
      return;
    }
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
  }
};

int main(void)
{
  int t, k, n, value;
  scanf("%d", &t);
  while (t--)
  {
    insert();
    scanf("%d", &k);
    Node* del = findNode(head, k);
    Solution ob;
    if (del != nullptr && del->next != nullptr)
    {
      ob.deleteNode(del);
    }
    printList(head);
  }
  return (0);
}

// Same method:- 

void deleteNode(Node* del)
{
  del->data = del->next->data;
  del->next = (del->next)->next;
}
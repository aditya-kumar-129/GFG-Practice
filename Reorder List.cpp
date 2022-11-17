#include <iostream>
using namespace std;
/* Linked list Node */
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

void reorderList(struct Node* head);

struct Node* newNode(int data)
{
  struct Node* new_Node = new Node(data);
  new_Node->data = data;
  new_Node->next = nullptr;
  return new_Node;
}

void printList(struct Node* Node)
{
  while (Node != nullptr)
  {
    printf("%d ", Node->data);
    Node = Node->next;
  }
  printf("\n");
}

void freeList(struct Node* head)
{
  struct Node* temp;
  while (head != nullptr)
  {

    temp = head;
    head = head->next;
    free(temp);
  }
}

Node* reverse(Node* head)
{
  Node* curr = head;
  Node* prev = nullptr, * next;
  while (curr != nullptr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void reorderList(Node* root)
{
  Node* slow = root, * fast = root, * head1 = root;
  Node* head2;
  while ((fast != nullptr) && (fast->next != nullptr))
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  head2 = slow->next;
  slow->next = nullptr;
  head2 = reverse(head2);

  Node* tmp = head1;
  head1 = head1->next;
  while (head2 != nullptr)
  {
    tmp->next = head2;
    head2 = head2->next;
    tmp = tmp->next;
    tmp->next = head1;
    head1 = head1->next;
    tmp = tmp->next;
  }
}
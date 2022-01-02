#include <iostream>
using namespace std;
/* Linked list Node */
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void reorderList(struct Node *head);

struct Node *newNode(int data)
{
  struct Node *new_Node = new Node(data);
  new_Node->data = data;
  new_Node->next = NULL;
  return new_Node;
}

void printList(struct Node *Node)
{
  while (Node != NULL)
  {
    printf("%d ", Node->data);
    Node = Node->next;
  }
  printf("\n");
}

void freeList(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {

    temp = head;
    head = head->next;
    free(temp);
  }
}

int main(void)
{
  int t, n, m, i, x;
  cin >> t;
  while (t--)
  {
    struct Node *temp, *head;
    cin >> n >> x;
    head = new Node(x);
    temp = head;
    for (i = 0; i < n - 1; i++)
    {
      cin >> x;
      temp->next = new Node(x);
      temp = temp->next;
    }
    reorderList(head);
    printList(head);
    freeList(head);
  }
  return 0;
}

Node *reverse(Node *head)
{
  Node *curr = head;
  Node *prev = NULL, *next;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void reorderList(Node *root)
{
  Node *slow = root, *fast = root, *head1 = root;
  Node *head2;
  while ((fast != NULL) && (fast->next != NULL))
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  head2 = slow->next;
  slow->next = NULL;
  head2 = reverse(head2);

  Node *tmp = head1;
  head1 = head1->next;
  while (head2 != NULL)
  {
    tmp->next = head2;
    head2 = head2->next;
    tmp = tmp->next;
    tmp->next = head1;
    head1 = head1->next;
    tmp = tmp->next;
  }
}
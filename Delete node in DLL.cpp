#include<iostream>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
  Node(int x)
  {
    data = x;
    next = NULL;
    prev = NULL;
  }
};

class Solution
{
public:
  Node* deleteNode(Node* head, int x)
  {
    if (head == NULL)
      return NULL;
    if (head->next == NULL)
    {
      delete head;
      return NULL;
    }
    Node* curr = head;
    if (x == 1)
    {
      curr->next->prev = NULL;
      head = curr->next;
      curr->next = NULL;
      delete curr;
      return head;
    }
    while (x != 1)
    {
      curr = curr->next;
      x--;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL)
      curr->next->prev = curr->prev;

    delete curr;
    return head;
  }
};

void printList(struct Node* node)
{
  while (node != NULL)
  {
    cout << node->data;
    node = node->next;
  }
  printf("\n");
}

int main()
{
  int t, x, n, i;
  cin>>t;
  while (t--)
  {
    struct Node* temp, * head = NULL;
    cin>>n;
    temp = NULL;
    for (i = 0; i < n; i++)
    {
      cin>>x;
      if (head == NULL)
      {
        head = new Node(x);
        temp = head;
      }
      else
      {
        Node* temp1 = new Node(x);
        temp->next = temp1;
        temp1->prev = temp;
        temp = temp->next;
      }
    }
    cin>>x;
    Solution ob;
    head = ob.deleteNode(head, x);
    printList(head);
    while (head->next != NULL)
    {
      temp = head;
      head = head->next;
      free(temp);
    }
    free(head);
  }
  return 0;
}
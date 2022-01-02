#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int coeff;
  int pow;
  struct Node *next;
  Node(int c, int p)
  {
    coeff = c;
    pow = p;
    next = NULL;
  }
};

void append(struct Node **head_ref, struct Node **tail_ref, int new_data, int new_data1)
{
  struct Node *new_node = new Node(new_data, new_data1);
  if (*head_ref == NULL)
    *head_ref = new_node;
  else
    (*tail_ref)->next = new_node;
  *tail_ref = new_node;
}

void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d %d ", temp->coeff, temp->pow);
    temp = temp->next;
  }
}

Node *addPolynomial(Node *p1, Node *p2);
void create_node(int x, int y, struct Node **temp)
{
  struct Node *r, *z;
  z = *temp;
  if (z == NULL)
  {
    r = new Node(x, y);
    *temp = r;
    r->next = NULL;
  }
  else
  {
    r->next = new Node(x, y);
    r = r->next;
    r->next = NULL;
  }
}

class Solution
{
public:
  Node *addPolynomial(Node *p1, Node *p2)
  {
    Node *ptr1 = p1, *ptr2 = p2;
    Node *dummy = new Node(-1, -1);
    Node *ptr3 = dummy;
    while (ptr1 != NULL && ptr2 != NULL)
    {
      if (ptr1->pow > ptr2->pow)
      {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
      }
      else if (ptr1->pow < ptr2->pow)
      {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
      }
      else
      {
        ptr1->coeff = ptr1->coeff + ptr2->coeff;
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      }
      ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
      ptr3->next = ptr1;
      ptr1 = ptr1->next;
      ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
      ptr3->next = ptr2;
      ptr2 = ptr2->next;
      ptr3 = ptr3->next;
    }
    return dummy->next;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      append(&poly1, &tail1, x, y);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      append(&poly2, &tail2, x, y);
    }
    Solution obj;
    Node *sum = obj.addPolynomial(poly1, poly2);
    for (Node *ptr = sum; ptr; ptr = ptr->next)
    {
      cout << ptr->coeff << "x^" << ptr->pow;
      if (ptr->next)
        cout << " + ";
    }
    cout << endl;
  }
}
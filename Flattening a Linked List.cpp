#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
  struct Node* bottom;
  Node(int x)
  {
    data = x;
    next = nullptr;
    bottom = nullptr;
  }
};

void printList(Node* Node)
{
  while (Node != nullptr)
  {
    printf("%d ", Node->data);
    Node = Node->bottom;
  }
}

Node* flatten(Node* root);
int main(void)
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, flag = 1, flag1 = 1;
    struct Node* temp = nullptr;
    struct Node* head = nullptr;
    struct Node* pre = nullptr;
    struct Node* tempB = nullptr;
    struct Node* preB = nullptr;
    cin >> n;
    int work[n];
    for (int i = 0; i < n; i++)
      cin >> work[i];
    for (int i = 0; i < n; i++)
    {
      m = work[i];
      --m;
      int data;
      scanf("%d", &data);
      temp = new Node(data);
      temp->next = nullptr;
      temp->bottom = nullptr;
      if (flag)
      {
        head = temp;
        pre = temp;
        flag = 0;
        flag1 = 1;
      }
      else
      {
        pre->next = temp;
        pre = temp;
        flag1 = 1;
      }
      for (int j = 0; j < m; j++)
      {
        int temp_data;
        scanf("%d", &temp_data);
        tempB = new Node(temp_data);
        if (flag1)
        {
          temp->bottom = tempB;
          preB = tempB;
          flag1 = 0;
        }
        else
        {
          preB->bottom = tempB;
          preB = tempB;
        }
      }
    }
    Node* fun = head;
    Node* fun2 = head;
    Node* root = flatten(head);
    printList(root);
    cout << endl;
  }
  return 0;
}

Node* merge(Node* a, Node* b)
{
  if (a == nullptr)
    return b;
  if (b == nullptr)
    return a;
  Node* result;
  if (a->data < b->data)
  {
    result = a;
    result->bottom = merge(a->bottom, b);
  }
  else
  {
    result = b;
    result->bottom = merge(a, b->bottom);
  }
  result->next = nullptr;
  return result;
}
Node* flatten(Node* root)
{
  if (root == nullptr || root->next == nullptr)
    return root;
  root->next = flatten(root->next);
  root = merge(root, root->next);
  return root;
}
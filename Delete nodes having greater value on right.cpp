#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

void print(Node* root)
{
  Node* temp = root;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

class Solution
{
public:
  Node* reverse(Node* head)
  {
    Node* next = nullptr, * curr = head, * prev = nullptr;
    while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return head;
  }
  Node* compute(Node* head)
  {
    head = reverse(head);
    struct Node* current = head, * maxnode = head, * temp;

    while (current != nullptr && current->next != nullptr)
    {
      if (current->next->data < maxnode->data)
      {
        temp = current->next;
        current->next = temp->next;
        free(temp);
      }
      else
      {
        current = current->next;
        maxnode = current;
      }
    }
    head = reverse(head);
    return head;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int K;
    cin >> K;
    struct Node* head = nullptr;
    struct Node* temp = head;
    for (int i = 0;i < K;i++) {
      int data;
      cin >> data;
      if (head == nullptr)
        head = temp = new Node(data);
      else
      {
        temp->next = new Node(data);
        temp = temp->next;
      }
    }
    Solution ob;
    Node* result = ob.compute(head);
    print(result);
    cout << endl;
  }
}
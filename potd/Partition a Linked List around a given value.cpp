#include <bits/stdc++.h>
using namespace std;

struct Node* partition(struct Node* head, int x) {
  struct Node* smallerHead = nullptr, * smallerLast = nullptr;
  struct Node* greaterLast = nullptr, * greaterHead = nullptr;
  struct Node* equalHead = nullptr, * equalLast = nullptr;

  while (head != nullptr)
  {
    if (head->data == x)
    {
      if (equalHead == nullptr)
        equalHead = equalLast = head;
      else
      {
        equalLast->next = head;
        equalLast = equalLast->next;
      }
    }
    else if (head->data < x)
    {
      if (smallerHead == nullptr)
        smallerLast = smallerHead = head;
      else
      {
        smallerLast->next = head;
        smallerLast = head;
      }
    }
    else
    {
      if (greaterHead == nullptr)
        greaterLast = greaterHead = head;
      else
      {
        greaterLast->next = head;
        greaterLast = head;
      }
    }
    head = head->next;
  }
  if (greaterLast != nullptr)
    greaterLast->next = nullptr;

  if (smallerHead == nullptr)
  {
    if (equalHead == nullptr)
      return greaterHead;
    equalLast->next = greaterHead;
    return equalHead;
  }

  if (equalHead == nullptr)
  {
    smallerLast->next = greaterHead;
    return smallerHead;
  }

  smallerLast->next = equalHead;
  equalLast->next = greaterHead;
  return smallerHead;
}

struct Node {
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = nullptr;
  }
};

void printList(struct Node* node) {
  while (node != nullptr) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main(void) {
  int t;
  cin >> t;

  while (t--) {
    struct Node* head = nullptr;
    struct Node* temp = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int value;
      cin >> value;
      if (i == 0) {
        head = new Node(value);
        temp = head;
      }
      else {
        temp->next = new Node(value);
        temp = temp->next;
      }
    }
    int k;
    cin >> k;
    head = partition(head, k);
    printList(head);
  }

  return (0);
}


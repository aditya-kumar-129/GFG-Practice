#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* partition(Node* head, int x) {
  Node* smallerHead = nullptr, * smallerLast = nullptr;
  Node* greaterLast = nullptr, * greaterHead = nullptr;
  Node* equalHead = nullptr, * equalLast = nullptr;

  while (head) {
    if (head->data == x) {
      if (!equalHead) equalHead = equalLast = head;
      else {
        equalLast->next = head;
        equalLast = equalLast->next;
      }
    }
    else if (head->data < x) {
      if (!smallerHead) smallerLast = smallerHead = head;
      else {
        smallerLast->next = head;
        smallerLast = head;
      }
    }
    else {
      if (!greaterHead) greaterLast = greaterHead = head;
      else {
        greaterLast->next = head;
        greaterLast = head;
      }
    }
    head = head->next;
  }
  if (greaterLast) greaterLast->next = nullptr;
  if (!smallerHead) {
    if (!equalHead) return greaterHead;
    equalLast->next = greaterHead;
    return equalHead;
  }
  if (!equalHead) {
    smallerLast->next = greaterHead;
    return smallerHead;
  }
  smallerLast->next = equalHead;
  equalLast->next = greaterHead;
  return smallerHead;
}
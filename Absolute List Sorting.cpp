// Question Link :- https://practice.geeksforgeeks.org/problems/absolute-list-sorting/0

#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* next;
  int data;
};

class Solution {
public:
  void sortList(Node** head) {
    Node* prev = (*head);
    Node* curr = (*head)->next;
    while (curr != nullptr) {
      if (curr->data < prev->data) {
        prev->next = curr->next;
        curr->next = (*head);
        (*head) = curr;
        curr = prev;
      }
      else prev = curr;
      curr = curr->next;
    }
  }
};
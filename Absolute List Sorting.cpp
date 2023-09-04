// Question Link :- https://practice.geeksforgeeks.org/problems/absolute-list-sorting/0

#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* next;
  int data;
};

class Solution {
public:
  Node* sortList(Node* head) {
    Node* prev = head, * curr = head->next;
    while (curr) {
      if (curr->data < prev->data) {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        curr = prev;
      }
      else prev = curr;
      curr = curr->next;
    }
    return head;
  }
};
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  void linkdelete(struct Node* head, int M, int N) {
    Node* curr = head, * tempNode;
    int count;
    while (curr) {
      for (count = 1; count < M && curr != nullptr; count++)
        curr = curr->next;
      if (curr == nullptr) return;
      tempNode = curr->next;
      for (count = 1; count <= N && tempNode != nullptr; count++) {
        Node* temp = tempNode;
        tempNode = tempNode->next;
        free(temp);
      }
      curr->next = tempNode;
      curr = tempNode;
    }
  }
};
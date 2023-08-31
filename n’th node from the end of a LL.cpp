#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

int getNthFromLast(Node* head, int n) {
  int len = 0, i;
  struct Node* temp = head;
  while (temp) {
    temp = temp->next;
    len++;
  }
  if (len < n) return -1;
  temp = head;
  for (i = 1; i < len - n + 1; i++)
    temp = temp->next;
  return temp->data;
}
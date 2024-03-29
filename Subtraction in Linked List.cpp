#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

Node* reverseList(Node* head, int& count) {
  if (!head || !head->next) return head;
  Node* prev = nullptr, * curr = head;
  while (curr) {
    count++;
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// Removing the prefix zeros from LL
Node* removeZeros(Node* subReverse) {
  while (subReverse->next != nullptr && subReverse->data == 0) {
    Node* next = subReverse->next;
    free(subReverse);
    subReverse = next;
  }
  return subReverse;
}

Node* subLinkedList(Node* l1, Node* l2) {
  int firstCount = 0, secondCount = 0;
  l1 = removeZeros(l1); // Removing the prefix zeros from LL
  l2 = removeZeros(l2);

  Node* firstReverse = reverseList(l1, firstCount);   // Reverse of the first LL and get the length of the LL
  Node* secondReverse = reverseList(l2, secondCount); // Reverse of the second LL and get the length of the LL

  if (secondCount > firstCount) // Adjusting so that the diff should be greater - smaller
    swap(firstReverse, secondReverse);
  // In case when the left most digit of second LL is greater than the first LL
  else if (firstCount == secondCount) {
    if (l1->data < l2->data)
      swap(firstReverse, secondReverse);
  }

  Node* substract = nullptr;     // Substract Linkedlist trail
  Node* substractHead = nullptr; // Head of the substracted LL.
  int carry = 0;
  while (firstReverse) {
    firstReverse->data += carry;
    carry = 0;
    int diff = 0;
    if (secondReverse) {
      if (firstReverse->data < secondReverse->data) {
        firstReverse->data += 10; //If the first elem is smaller then taking the carry
        carry = -1;               // Decremented from the previous
      }
      diff = firstReverse->data - secondReverse->data;
      secondReverse = secondReverse->next;
    }
    else {
      if (firstReverse->data >= 0) diff = firstReverse->data;
      //Negative means the previous when it gave carry, it had 0, so need to take carry again
      else {
        firstReverse->data += 10;
        carry = -1;
        diff = firstReverse->data;
      }
    }
    firstReverse = firstReverse->next;
    Node* diffNode = new Node(diff);
    if (!substract) {
      substract = diffNode;
      substractHead = diffNode;
    }
    else {
      substract->next = diffNode;
      substract = substract->next;
    }
  }
  int dum = 0;
  Node* subReverse = reverseList(substractHead, dum);
  subReverse = removeZeros(subReverse); // Removing the prefix zeros from the starting of LL
  return subReverse;
}
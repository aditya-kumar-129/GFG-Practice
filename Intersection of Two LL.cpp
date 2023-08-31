#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class Solution {
public:
  Node* findIntersection(Node* head1, Node* head2) {
    Node* head = nullptr, * tail = nullptr, * temp = head2;
    unordered_map<int, int> mp;
    while (temp != nullptr) {
      mp[temp->data]++;
      temp = temp->next;
    }
    temp = head1;
    while (temp) {
      if (mp.find(temp->data) != mp.end()) {
        Node* n = new Node(temp->data);
        if (!head) {
          head = n;
          tail = n;
        }
        else {
          tail->next = n;
          tail = tail->next;
        }
      }
      temp = temp->next;
    }
    return head;
  }
};
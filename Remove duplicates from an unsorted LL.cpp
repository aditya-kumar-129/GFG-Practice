#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class Solution {
public:
  Node* removeDuplicates(Node* head) {
    unordered_set<int> st;
    Node* curr = head;
    Node* prev = head;
    while (curr) {
      if (st.find(curr->data) != st.end()) {
        prev->next = curr->next;
        delete (curr);
      }
      else {
        st.insert(curr->data);
        prev = curr;
      }
      curr = prev->next;
    }
    return head;
  }
};
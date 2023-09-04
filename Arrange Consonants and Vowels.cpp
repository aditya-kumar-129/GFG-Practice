// Question Link :- https://practice.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

// Method 1:-  In this case we are forming two LL, One for vowel and one for Consonant.
// As soon as the traversal gets finished just point the vowel next to consonant head;
// Space Complexity :- O(n) for creating a entire new LL.
Node* arrange(Node* head) {
  Node* vowel = nullptr, * consonant = nullptr, * start = nullptr, * end = nullptr;
  while (head) {
    char x = head->data;
    Node* newNode = new Node(x);
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
      if (!vowel) vowel = newNode, start = vowel;
      else vowel->next = newNode, vowel = vowel->next;
    }
    else {
      if (!consonant) consonant = newNode, end = consonant;
      else consonant->next = newNode, consonant = consonant->next;
    }
    head = head->next;
  }
  // In case when there is no vowel in the incoming LL then we have to return the head of the consonant LL
  if (!start) return end;
  // Connecting the vowel and consonant LL
  vowel->next = end;
  return start;
}

// Method 2 :- BRUTE FORCE APPROACH
Node* arrange(Node* head) {
  vector<char> vowel, consonant;
  Node* temp = head;
  while (temp) {
    if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u') {
      vowel.push_back(temp->data);
    }
    else consonant.push_back(temp->data);
    temp = temp->next;
  }
  for (auto e : consonant) vowel.push_back(e);
  int len = vowel.size(), count = 1;
  Node* newNode = new Node(vowel[0]);
  Node* head1 = newNode;
  while (count != len) {
    Node* temp = new Node(vowel[count]);
    newNode->next = temp;
    newNode = newNode->next;
    count++;
  }
  return head1;
}

// OPTIMUM SOLUTION
// SPACE COMPLEXITY:- O(1);
bool isVowel(char x) {
  return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

Node* arrange(Node* head) {
  Node* newHead = head, * latestVowel, * curr = head;
  if (!head) return nullptr;
  // We need to discover the first vowel in the list. It is going to be the returned head, and also the initial latestVowel.
  if (isVowel(head->data))
    // first element is a vowel. It will also be the new head and the initial latestVowel;
    latestVowel = head;
  else {
    // First element is not a vowel. Iterate through the list until we find a vowel.
    // Note that curr points to the element *before* the element with the vowel.
    while (curr->next && !isVowel(curr->next->data)) curr = curr->next;

    // This is an edge case where there are only consonants in the list.
    if (!curr->next) return head;

    // Set the initial latestVowel and the new head to the vowel item that we found.
    // Relink the chain of consonants after that vowel item:
    // old_head_consonant->consonant1->consonant2->
    // vowel->rest_of_list becomes vowel->old_head_consonant->consonant1-> consonant2->rest_of_list
    latestVowel = newHead = curr->next;
    curr->next = curr->next->next;
    latestVowel->next = head;
  }

  // Now traverse the list. Curr is always the item *before* the one we are checking, so that we can use it to re-link.
  while (curr && curr->next) {
    if (isVowel(curr->next->data)) {
      // The next discovered item is a vowel
      if (curr == latestVowel) {
        // If it comes directly after the previous vowel, we don't need to
        // move items around, just mark the new latestVowel and advance curr.
        latestVowel = curr = curr->next;
      }
      else {
        // But if it comes after an intervening chain of consonants, we need to chain the newly discovered vowel right after the old vowel.
        // Curr is not changed as after the re-linking it will have a new next, that has not been checked yet,
        // and we always keep curr at one before the next to check.
        Node* temp = latestVowel->next;
        // Chain in new vowel
        latestVowel->next = curr->next;
        // Advance latestVowel
        latestVowel = latestVowel->next;
        // Remove found vowel from previous place
        curr->next = curr->next->next;
        // Re-link chain of consonants after latestVowel
        latestVowel->next = temp;
      }
    }
    else
      // No vowel in the next element, advance curr.
      curr = curr->next;
  }
  return newHead;
}
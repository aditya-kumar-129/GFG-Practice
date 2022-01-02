#include <bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void printlist(Node *head)
{
  if (head == NULL)
    return;
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void append(struct Node **headRef, char data)
{
  struct Node *new_node = new Node(data);
  struct Node *last = *headRef;
  if (*headRef == NULL)
  {
    *headRef = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}

// Method 1:-  In this case we are forming two LL, One for vowel and one for Consonant.
// As soon as the traversal gets finished just point the vowel next to consonant head;
struct Node *arrange(Node *head)
{
  Node *vowel = NULL, *consonant = NULL, *start = NULL, *end = NULL;
  while (head != NULL)
  {
    char x = head->data;
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    {
      if (!vowel)
      {
        vowel = new Node(x);
        start = vowel;
      }
      else
      {
        vowel->next = new Node(x);
        vowel = vowel->next;
      }
    }
    else
    {
      if (!consonant)
      {
        consonant = new Node(x);
        end = consonant;
      }
      else
      {
        consonant->next = new Node(x);
        consonant = consonant->next;
      }
    }
    head = head->next;
  }
  // In case when there is no vowel in the incoming LL then we have to return the head of the consonant LL
  if (start == NULL)
    return end;
  // Connecting the vowel and consonant LL
  vowel->next = end;
  return start;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    char tmp;
    struct Node *head = NULL;
    cin >> n;
    while (n--)
    {
      cin >> tmp;
      append(&head, tmp);
    }
    head = arrange(head);
    printlist(head);
  }
  return 0;
}

// Method 2 :- BRUTE FORCE APPROACH
struct Node *arrange(Node *head)
{
  vector<char> vowel;
  vector<char> cons;
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
      vowel.push_back(temp->data);
    else
      cons.push_back(temp->data);
    temp = temp->next;
  }
  for (auto e : cons)
    vowel.push_back(e);
  int len = vowel.size();
  int count = 1;
  Node *newNode = new Node(vowel[0]);
  Node *head1 = newNode;
  while (count != len)
  {
    Node *temp = new Node(vowel[count]);
    newNode->next = temp;
    newNode = newNode->next;
    count++;
  }
  return head1;
}
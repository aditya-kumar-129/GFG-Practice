#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void printList(Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

class Solution
{
public:
  // Method 2:- Below implmentation does not uses any space Space Complexity = O(1)
  // It uses the concept of Merge Sort
  // Iterative approach
  // SPACE COMPLEXITY :- O(N) or O(n*k);
  // TIME COMPLEXITY :- O(nk Logk)
  // This method gives optimum solution 
  Node *merge(Node *first, Node *second)
  {
    Node *head = new Node(-1);
    Node *start = head;
    while (first && second)
    {
      if (first->data <= second->data)
      {
        start->next = first;
        first = first->next;
      }
      else
      {
        start->next = second;
        second = second->next;
      }
      start = start->next;
    }
    if (first)
      start->next = first;
    if (second)
      start->next = second;
    return head->next;
  }
  Node *mergeKLists(Node *arr[], int K)
  {
    Node *temp = NULL;
    for (int i = 0; i < K; i++)
      temp = merge(temp, arr[i]);
    return temp;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
      int n, x;
      cin >> n >> x;
      arr[j] = new Node(x);
      Node *curr = arr[j];
      n--;
      for (int i = 0; i < n; i++)
      {
        cin >> x;
        Node *temp = new Node(x);
        curr->next = temp;
        curr = temp;
      }
    }
    Solution obj;
    Node *res = obj.mergeKLists(arr, N);
    printList(res);
  }
  return 0;
}

// BRUTE FORCE APPROACH
Node *mergeKLists(Node *arr[], int k)
{
  vector<int> v;
  for (int i = 0; i < k; i++)
  {
    Node *temp = arr[i];
    while (temp != NULL)
    {
      v.push_back(temp->data);
      temp = temp->next;
    }
  }
  sort(v.begin(), v.end());
  int len = v.size();
  Node *newNode = new Node(-1);
  Node *head = newNode;
  for (int i = 0; i < len; i++)
  {
    Node *temp = new Node(v[i]);
    newNode->next = temp;
    newNode = newNode->next;
  }
  return head->next;
}

// Recursive approach
Node *merge(Node *a, Node *b)
{
  Node *ans = NULL;
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;
  if (a->data <= b->data)
  {
    ans = a;
    ans->next = merge(a->next, b);
  }
  else if (b->data < a->data)
  {
    ans = b;
    ans->next = merge(a, b->next);
  }
  return ans;
}
Node *mergeKLists(Node *arr[], int K)
{
  for (int i = 1; i < K; i++)
    arr[0] = merge(arr[0], arr[i]);
  return arr[0];
}
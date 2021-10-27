#include <bits/stdc++.h>
using namespace std;

/* For more information related to the defination of node creation Follow thw bwlow link:-
https://stackoverflow.com/questions/58059499/different-type-of-node-created
*/
struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

//Below funtion is used to create the loop (the value of x represents the position at which the tail forms the loop)
void loopHere(Node *head, Node *tail, int position)
{
  if (position == 0)
    return;
  Node *walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

class Solution
{
public:
  //Function to check if the linked list has a loop.
  /* Refer the article for understanding the solution following the below link :-
  https://www.javatpoint.com/detect-loop-in-a-linked-list
  we have used Floyd's cycle-finding algorithm, also known as tortoise and hare algorithm.
  */
  bool detectLoop(Node *head)
  {
    Node *fast = head;
    Node *slow = head;
    while (fast && slow && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    // n represents the total number of nodes present in the linked list where as num represents the value to be stored in the node
    int n, num;
    cin >> n;
    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 0; i < n - 1; i++)
    {
      cin >> num;
      //Adding the new nodes at the end of the linked list
      tail->next = new Node(num);
      tail = tail->next;
    }
    int pos;
    cin >> pos;
    loopHere(head, tail, pos);
    Solution ob;
    if (ob.detectLoop(head))
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
}
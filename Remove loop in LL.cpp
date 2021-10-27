#include <iostream>
using namespace std;
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

//Loop is being created using the below function
void loopHere(Node *head, Node *tail, int position)
{
  if (position == 0)
    return;
  Node *walk = head;
  for (int i = 1; i < position; i++)
    walk = walk->next;
  tail->next = walk;
}

// Checking if any loop exist or not
bool isLoop(Node *head)
{
  if (!head)
    return false;
  Node *fast = head->next;
  Node *slow = head;
  while (fast != slow)
  {
    if (!fast || !fast->next)
      return false;
    fast = fast->next->next;
    slow = slow->next;
  }
  return true;
}

// I don't know why we have used this function
int length(Node *head)
{
  int ret = 0;
  while (head)
  {
    ret++;
    head = head->next;
  }
  return ret;
}

class Solution
{
public:
  //Function to remove a loop in the linked list.
  /*
    So basically we run the code to detect if their is any loop present in the linked list or not (first 2 lines)
    and if exist (remaing lines) then procedure to remove it.

    See the below article to understand the procedure 
    https://www.codesdope.com/blog/article/detect-and-remove-loop-in-a-linked-list/
    
    Only thing that i can't undestand is the secode if statement like why it is necessory to write that condition
    if (fast == head)
    {
      while (fast->next != head)
        fast = fast->next;
      fast->next = NULL;
    }
  */
  void removeLoop(Node *head)
  {
    if (head == NULL or head->next == nullptr)
      return;
    auto slow = head;
    auto fast = head;
    while (fast and fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        if (fast == head)
        {
          while (fast->next != head)
            fast = fast->next;
          fast->next = NULL;
        }
        else
        {
          fast = head;
          while (fast->next != slow->next)
          {
            fast = fast->next;
            slow = slow->next;
          }
          slow->next = NULL;
          break;
        }
      }
    }
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, num;
    cin >> n;
    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 0; i < n - 1; i++)
    {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }
    int pos;
    cin >> pos;
    loopHere(head, tail, pos);
    Solution ob;
    ob.removeLoop(head);
    if (isLoop(head) || length(head) != n)
      cout << "0\n";
    else
      cout << "1\n";
  }
  return 0;
}
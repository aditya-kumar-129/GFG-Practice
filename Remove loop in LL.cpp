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

// This function is used to calculate the length of the linked list so as to compare whether loop is removed or not
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
  /*
    See the below youtube video to understand the logic behind the solution of the problem
    https://www.youtube.com/watch?v=jcZtMh_jov0
  */
class Solution
{
public:
  Node* detectLoopNode(Node* head)
  {
    Node* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)   // Loop detected
      {
        slow = head;
        // In this case even if the slow and fast pointer points to the head of the LL then also the while used in the removeloop() will handle this case also
        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return fast;  // first looping Node;
      }
    }
    return NULL;
  }

  void removeLoop(Node* head)
  {
    Node* loopNode = detectLoopNode(head);
    if (loopNode == NULL)       // There is no loop
      return;
    Node* temp = loopNode->next;
    while (temp->next != loopNode)
      temp = temp->next;
    temp->next = NULL; 
    return;
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
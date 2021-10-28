/*
  You can refer the below video explanation for more clearance:-
  https://youtu.be/SgQ0VV3eM7Q
  You can refer the below article for more information related to inbuilt function:-
  https://www.geeksforgeeks.org/queuepush-and-queuepop-in-cpp-stl/
  preview:-
  1) push() function is used to insert an element at the back of the queue. The element is added to the queue container and the size of the queue is increased by 1.
  2) pop() function is used to remove an element from the front of the queue(oldest element in the queue). The element is removed to the queue container and the size of the queue is decreased by 1.
*/
#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
  queue<int> q1;
  queue<int> q2;

public:
  void push(int);
  int pop();
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    QueueStack *qs = new QueueStack();
    int Q;
    cin >> Q;
    while (Q--)
    {
      int QueryType = 0;
      cin >> QueryType;
      if (QueryType == 1)
      {
        int a;
        cin >> a;
        qs->push(a);
      }
      else if (QueryType == 2)
        cout << qs->pop() << " ";
    }
    cout << endl;
  }
}

//Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
  q2.push(x);
  while (!q1.empty())
  {
    q2.push(q1.front());
    q1.pop();
  }
  swap(q1, q2);
}

//Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
  // Your Code
  if (q1.empty())
    return -1;
  int popped_number = q1.front();
  q1.pop();
  return popped_number;
}
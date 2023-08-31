// Youtube Video Link :- https://youtu.be/BJE3VEQWtIs

#include <bits/stdc++.h>
using namespace std;

class StackQueue {
private:
  stack<int> s1;
  stack<int> s2;
public:
  void push(int B);
  int pop();
};

//Function to push an element in queue by using 2 stacks.
void StackQueue::push(int x) {
  s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue::pop() {
  if (s1.empty() && s2.empty()) return -1;

  if (s2.empty()) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
  int x = s2.top();
  s2.pop();
  return x;
}


// Do you know when we should use two stacks to implement a queue ?
// I was asked in the internship interview of a company two years ago.
// The application for this implementation is to separate read & write of a queue in multi - processing.
// One of the stack is for read, and another is for write.They only interfere each other when the former one is full or latter is empty.
// This is not only a trick. :)

// When there's only one thread doing the read/write operation to the stack, there will always one stack empty. However, in a multi-thread application, if we have only one queue, for thread-safety, either read or write will lock the whole queue. In the two stack implementation, as long as the second stack is not empty, push operation will not lock the stack for pop.
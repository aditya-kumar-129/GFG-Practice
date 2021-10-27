// So their are two ways to solve this problem
/* method 1:- Using auxilary stack in order to track all the min values that came along while pushing the element so that whenever we we pop the min element we can identify what is the min element in the remaing elements of the stack.
For more info refer the below link
https://www.techiedelight.com/design-stack-which-returns-minimum-element-constant-time/
*/

// Below is the code of the above method

/*
#include <iostream>
#include <stack>
using namespace std;

class Stack
{
  stack<int> s;   // main stack to store elements
  stack<int> aux; // auxiliary stack to store minimum elements

public:
  void push(int x)
  {
    // push the given element into the main stack
    s.push(x);
    // if the auxiliary stack is empty, push the given element into it
    if (aux.empty())
      aux.push(x);
    else
    {
      // push the given element into the auxiliary stack if it is less than or equal to the current minimum
      if (aux.top() >= x)
        aux.push(x);
    }
  }

  // Removes the top element from the stack and returns it
  int pop()
  {
    if (s.empty())
    {
      cout << "Stack underflow!!" << endl;
      return -1;
    }
    int top = s.top();
    s.pop();

    // remove the top element from the auxiliary stack only if it is minimum
    if (top == aux.top())
      aux.pop();
    return top;
  }
  
  int min()
  {
    if (aux.empty())
    {
      cout << "Stack underflow!! ";
      return -1;
    }
    return aux.top();
  }
};

int main()
{
  Stack s;
  s.push(6);
  cout << s.min() << endl; // prints 6
  s.push(7);
  cout << s.min() << endl; // prints
  s.push(8);
  cout << s.min() << endl; // prints
  s.push(5);
  cout << s.min() << endl; // prints
  s.push(3);
  cout << s.min() << endl; // prints
  s.pop();
  cout << s.min() << endl; // prints
  s.push(10);
  cout << s.min() << endl; // prints 5
  s.pop();
  cout << s.min() << endl; // prints 5
  s.pop();
  cout << s.min() << endl; // prints 6
  return 0;
}*/

/*
Method 2 :- In this method we modify the element while pushing it under the stack under some condition 
Refer the below article for more details:-
https://www.techiedelight.com/design-a-stack-which-returns-minimum-element-without-using-auxiliary-stack/

Refer the below youtube video tutorial for more explaination:-
https://www.youtube.com/watch?v=QMlDCR9xyd8


below is the code for the implementation of the above method:-
*/

#include <iostream>
#include <stack>
using namespace std;

class Stack
{
  stack<int> s;
  // variable to store the minimum element
  int min;

public:
  // Inserts a given element on top of the stack
  void push(int x)
  {
    if (s.empty())
    {
      s.push(x);
      min = x;
    }
    else if (x > min)
      s.push(x);
    else
    {
      s.push(2 * x - min);
      min = x;
    }
  }

  // Removes the top element from the stack and returns it
  void pop()
  {
    if (s.empty())
      cout << "Stack underflow!!" << endl;
    int top = s.top();
    if (top < min)
      min = 2 * min - top;
    s.pop();
  }

  // Returns the minimum element from the stack in constant time
  int minimum()
  {
    return min;
  }
};

int main()
{
  Stack s;
  s.push(6);
  cout << s.minimum() << endl;
  s.push(7);
  cout << s.minimum() << endl;
  s.push(5);
  cout << s.minimum() << endl;
  s.push(3);
  cout << s.minimum() << endl;
  s.pop();
  cout << s.minimum() << endl;
  s.pop();
  cout << s.minimum() << endl;
  return 0;
}
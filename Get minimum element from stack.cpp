// So their are two ways to solve this problem
/* method 1:- Using auxilary stack in order to track all the min values that came along while pushing the element so that whenever we the min element we can identify what is the next min element in the remaining elements of the stack.
For more info refer the below link
https://www.techiedelight.com/design-stack-which-returns-minimum-element-constant-time/
*/

// Time complexity:- O(1)
// Space Complexity :- O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
  stack<int> aux;
  stack<int> s;
public:

  int getMin() 
  {
    if (aux.empty())
      return -1;
    else
      return aux.top();
  }
  int pop() 
  {
    if (s.empty()) 
      return -1;
    else 
    {
      int pop_val = s.top();
      if (s.top() == aux.top()) 
        aux.pop();
      s.pop();
      return pop_val;
    }
  }
  void push(int x) 
  {
    s.push(x);
    if (aux.empty() || aux.top() >= x) 
      aux.push(x);
  }
};

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    int q;
    cin >> q;
    Solution ob;
    while (q--) 
    {
      int qt;
      cin >> qt;
      if (qt == 1)
      {
        int att;
        cin >> att;
        ob.push(att);
      }
      else if (qt == 2)
        cout << ob.pop() << " ";
      else if (qt == 3)
        cout << ob.getMin() << " ";
    }
    cout << endl;
  }
  return 0;
}

/*
Method 2 :- OPTIMISED PART
Refer the below article for more details:-
https://www.techiedelight.com/design-a-stack-which-returns-minimum-element-without-using-auxiliary-stack/

Refer the below youtube video tutorial for more explaination:-
https://youtu.be/QTrNy-0Og7E
*/

// Time complexity:- O(1)
// Space Complexity :- O(1)


class Solution 
{
  int minEle;
  stack<int> s;
public:
  int getMin()
  {
    if (s.size() == 0)
      return -1;
    return minEle;
  }
  int pop()
  {
    if (s.empty())
      return -1;
    int t = s.top();
    s.pop();
    int res;
    if (t <= minEle)
    {
      res = minEle;
      minEle = 2 * minEle - t;
      return res;
    }
    else
      return t;
  }
  void push(int x) 
  {
    if (s.empty())
      minEle = x,s.push(x);
    else if (x <= minEle)
      s.push(2 * x - minEle),minEle = x;
    else
      s.push(x);
  }
};
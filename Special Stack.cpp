#include <iostream>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
stack<int> s;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, a;
    cin >> n;
    while (!isEmpty(s))
    {
      pop(s);
    }
    while (!isFull(s, n))
    {
      cin >> a;
      push(s, a);
    }
    cout << getMin(s) << endl;
  }
}

int minelem;
void push(stack<int> &s, int a)
{
  if (s.empty())
    minelem = a;
  if (a >= minelem)
    s.push(a);
  else
  {
    s.push(2 * a - minelem);
    minelem = a;
  }
  return;
}

bool isFull(stack<int> &s, int n)
{
  if (s.size() >= n)
    return true;
  return false;
}

bool isEmpty(stack<int> &s)
{
  if (s.empty())
    return true;
  else
    return false;
}

int pop(stack<int> &s)
{
  if (s.top() >= minelem)
  {
    int temp = s.top();
    s.pop();
    return temp;
  }
  else
  {
    int temp = minelem;
    minelem = 2 * minelem - s.top();
    s.pop();
    return temp;
  }
}

int getMin(stack<int> &s)
{
  return minelem;
}
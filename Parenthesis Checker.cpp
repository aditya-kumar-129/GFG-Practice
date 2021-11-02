#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool ispar(string str)
  {
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        s.push(str[i]);
      //IF current current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.
      else if (s.empty())
        return false;
      else
      {
        char top = s.top();
        if ((str[i] == ')' && top == '(') || (str[i] == '}' && top == '{') || (str[i] == ']' && top == '['))
          s.pop();
        else
          return false;
      }
    }
    // Check Empty Stack
    return s.empty();
  }
};

int main()
{
  int t;
  string a;
  cin >> t;
  while (t--)
  {
    cin >> a;
    Solution obj;
    if (obj.ispar(a))
      cout << "balanced" << endl;
    else
      cout << "not balanced" << endl;
  }
}
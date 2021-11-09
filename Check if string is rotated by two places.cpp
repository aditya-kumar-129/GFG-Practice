/*
Below is the article used for solving the problem :- 
https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int leftrotate(string s, int d, string s2)
  {
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
    if (s == s2)
      return 1;
    else
      return 0;
  }

  bool isRotated(string str1, string str2)
  {
    if (leftrotate(str1, 2, str2))
      return true;
    else if (leftrotate(str1, str1.length() - 2, str2))
      return true;
    else
      return false;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    string b;
    cin >> s >> b;
    Solution obj;
    cout << obj.isRotated(s, b) << endl;
  }
  return 0;
}
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

// Have a look at the below article :- 
// https://www.geeksforgeeks.org/substring-in-cpp/
bool isRotated(string str1, string str2)
{
  if (str1.length() != str2.length())
    return false;
  if (str1.length() < 2)
    return str1.compare(str2) == 0;

  string clock_rot = "";
  string anticlock_rot = "";
  int len = str2.length();

  // Initialize string as anti-clockwise rotation
  anticlock_rot = anticlock_rot + str2.substr(len - 2, 2) + str2.substr(0, len - 2);
  // Initialize string as clock wise rotation
  clock_rot = clock_rot + str2.substr(2) + str2.substr(0, 2);
  // check if any of them is equal to string1
  return (str1.compare(clock_rot) == 0 || str1.compare(anticlock_rot) == 0);
}
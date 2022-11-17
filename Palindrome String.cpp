#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPalindrome(string str)
  {
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
      if (str[l++] != str[h--])
        return 0;
    return 1;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string rremove(string s) {
    pair<char, int> p;
    p.first = s[0];
    p.second = 1;
    string ans;
    for (int i = 1;i < s.size();i++)
    {
      if (s[i] == p.first)
        p.second++;
      else
      {
        if (p.second == 1)
        {
          ans += p.first;
          p.first = s[i];
          p.second = 1;
        }
        else
        {
          p.first = s[i];
          p.second = 1;
        }
      }
    }
    if (p.second == 1)
      ans += p.first;
    if (ans == s)
      return ans;
    return rremove(ans);
  }
};

// Way 2 :- 

class Solution {
public:
  string rremove(string str)
  {
    if (str.size() == 0) 
      return str;

    int i, k = 0;
    int len = str.size();

    for (i = 1; i < len; i++)
    {
      if (str[i - 1] != str[i])
        str[k++] = str[i - 1];
      else
        while (i < len && str[i - 1] == str[i])
          i++;
    }

    str[k++] = str[i - 1];
    str.erase(k);
    if (k != len)
      return rremove(str);
    return str;
  }
};
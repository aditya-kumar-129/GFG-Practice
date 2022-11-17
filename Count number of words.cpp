#include <bits/stdc++.h>
using namespace std;

int countWords(string s)
{
  int count = 0, flag = 0;
  for (int i = 0; i < s.length();)
  {
    if (isalpha(s[i]))
    {
      flag = 1;
      i++;
    }
    else if (s[i] == '\\')
    {
      if (flag == 1)
        count++;
      flag = 0;
      i += 2;
    }
    else if (s[i] == ' ')
    {
      if (flag == 1)
        count++;
      flag = 0;
      i++;
    }
  }
  if (flag)
    count++;
  return count;
}
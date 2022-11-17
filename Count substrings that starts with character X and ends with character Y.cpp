#include <bits/stdc++.h>
using namespace std;

int countSubstr(string str, int n, char x, char y)
{
  int tot_count = 0;
  // to store count of character 'x' up to the point the string 'str' has been traversed so far
  int count_x = 0;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == x)
      count_x++;
    // if true accumulate 'count_x' to 'tot_count'
    if (str[i] == y)
      tot_count += count_x;
  }
  return tot_count;
}
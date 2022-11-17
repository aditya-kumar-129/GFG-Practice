#include <bits/stdc++.h>
using namespace std;

// The below method will take O(n^2) time 
int longestSubstrDistinctChars(string str)
{
  int n = str.size();
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    vector<bool> visited(256);
    for (int j = i; j < n; j++)
    {
      if (visited[str[j]] == true)
        break;
      else
      {
        res = max(res, j - i + 1);
        visited[str[j]] = true;
      }
    }
    visited[str[i]] = false;
  }
  return res;
}

// How to solve the above problem in O(n) time complexity I don't get
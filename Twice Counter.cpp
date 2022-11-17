#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countWords(string arr[], int n)
  {
    map<string, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
      m[arr[i]]++;
    for (auto it : m)
      if (it.second == 2)
        count++;
    return count;
  }
};
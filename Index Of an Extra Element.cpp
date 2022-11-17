#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findExtra(int a[], int b[], int n)
  {
    map<int, int> m;
    for (int i = 0; i < n; i++)
      m[a[i]]++;
    for (int i = 0; i < n - 1; i++)
      m[b[i]]++;
    int extra_element;
    for (auto it : m)
      if (it.second == 1)
        extra_element = it.first;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == extra_element)
      {
        index = i;
        break;
      }
    }
    return index;
  }
};
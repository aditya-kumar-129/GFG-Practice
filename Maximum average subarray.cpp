#include <bits/stdc++.h>
using namespace std;

// Sliding window concept has been used here

class Solution
{
public:
  int findMaxAverage(int a[], int n, int k)
  {
    int ans = 0;
    for (int i = 0; i < k; i++)
      ans += a[i];
    int max_till_now = ans, index = 0;
    for (int i = k; i < n; i++)
    {
      ans += a[i] - a[i - k];
      if (ans > max_till_now)
      {
        max_till_now = ans;
        index = i - k + 1;
      }
    }
    return index;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void convertToWave(vector<int> &arr, int n)
  {
    for (int i = 0; i < n; i = i + 2)
    {
      if (i==n-1)
        break;
      swap(arr[i], arr[i+1]);
    }
  }
};
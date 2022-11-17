// Trapping Rain Water.cpp is same as of this problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxWater(int arr[], int n)
  {
    int left[n];
    int right[n];
    int water = 0;
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
      left[i] = max(left[i - 1], arr[i]);
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
      right[i] = max(right[i + 1], arr[i]);
    for (int i = 0; i < n; i++)
      water += min(left[i], right[i]) - arr[i];
    return water;
  }
};
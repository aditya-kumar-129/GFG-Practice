#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Two Pointers Algorithm
  // OPTIMUM SOLUTION
  bool findTriplets(int arr[], int n)
  {
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
      int l = i + 1;
      int r = n - 1;
      while (l < r)
      {
        if (arr[l] + arr[r] + arr[i] == 0)
          return true;
        else if (arr[l] + arr[r] + arr[i] < 0)
          l++;
        else
          r--;
      }
    }
    return false;
  }
};
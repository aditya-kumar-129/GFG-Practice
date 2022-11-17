#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Method 2:- OPTIMISED APPROACH
  // Time Complexity:- O(logn)
  // Space Complexity:- O(1)
  int findFloor(vector<long long> v, long long n, long long x) {
    long long low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
      long long mid = low + (high - low) / 2;
      if (v[mid] == x)
        return mid;
      else if (v[mid] < x)
      {
        ans = mid;
        low = mid + 1;
      }
      else
        high = mid - 1;
    }
    return ans;
  }
};

// Method 2:- Brute force approach
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int findFloor(vector<long long> v, long long n, long long x)
{
  for (long long i = n - 1; i >= 0; i--)
    if (v[i] <= x)
      return i;
  return -1;
}
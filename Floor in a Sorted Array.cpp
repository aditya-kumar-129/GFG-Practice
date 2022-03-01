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

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
      long long temp;
      cin >> temp;
      v.push_back(temp);
    }
    Solution obj;
    cout << obj.findFloor(v, n, x) << endl;
  }
  return 0;
}

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
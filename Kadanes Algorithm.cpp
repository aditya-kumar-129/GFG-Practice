#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxSubarraySum(int a[], int size)
  {
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < size; i++)
    {
      max_ending_here = max_ending_here + a[i];
      if (max_so_far < max_ending_here)
        max_so_far = max_ending_here;
      if (max_ending_here < 0)
        max_ending_here = 0;
    }
    return max_so_far;
  }
};

int main()
{
  int t, n;
  cin >> t;   //input testcases
  while (t--) //while testcases exist
  {
    cin >> n; //input size of array
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i]; //inputting elements of array
    Solution ob;
    cout << ob.maxSubarraySum(a, n) << endl;
  }
}
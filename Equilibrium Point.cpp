#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
  accumulate(): This function returns the sum of all the values lying in a range between [first, last) with the variable sum.
  accumulate(first, last, sum);
  */
  int equilibriumPoint(long long arr[], int n)
  {
    int sum = accumulate(arr, arr + n, 0);
    int left_sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (left_sum == sum - arr[i])
        return i + 1;
      left_sum += arr[i];
      sum -= arr[i];
    }
    return -1;
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
    long long a[n];
    for (long long i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.equilibriumPoint(a, n) << endl;
  }
  return 0;
}
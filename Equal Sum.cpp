#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
  accumulate(): This function returns the sum of all the values lying in a range between [first, last) with the variable sum.
  accumulate(first, last, sum);
  */
  string equilibrium(int *arr, int n)
  {
    int sum = accumulate(arr, arr + n, 0);
    int sum_left = 0, sum_right = sum;
    for (int i = 0; i < n; i++)
    {
      sum_right -= arr[i];
      if (sum_left == sum_right)
        return "YES";
      sum_left += arr[i];
    }
    return "NO";
  }
};
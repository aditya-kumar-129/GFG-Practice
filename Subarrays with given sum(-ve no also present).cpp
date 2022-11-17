#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subArraySum(int arr[], int n, int sum)
  {
    unordered_map<int, int> mp;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
      pre_sum += arr[i];
      if (pre_sum == sum)
        res++;
      if (mp.find(pre_sum - sum) != mp.end())
        res += mp[pre_sum - sum];
      mp[pre_sum]++;
    }
    return res;
  }
};
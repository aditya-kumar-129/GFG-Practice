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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, sum = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cin >> sum;
    Solution ob;
    cout << ob.subArraySum(arr, n, sum);
    cout << '\n';
  }
  return 0;
} // } Driver Code Ends
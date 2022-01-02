#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    auto ans = ob.equilibrium(a, n);
    cout << ans << "\n";
  }
  return 0;
}
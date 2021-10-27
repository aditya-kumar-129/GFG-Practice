// Here is the link of solution (second part which is more efficient I won't be able to understand)
// https://www.geeksforgeeks.org/sum-product-x-y-floornx-y/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  long long int sumofproduct(int n)
  {
    int res = 0;
    for (int x = 1; x <= n; x++)
    {
      int y = n / x;
      res += (y * x);
    }
    return res;
  }
};
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    Solution ob;
    long long int ans = ob.sumofproduct(n);
    cout << ans << "\n";
  }
  return 0;
}
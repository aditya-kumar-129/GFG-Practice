#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &a)
  {
    sort(a.begin(), a.end());
    auto it = --a.end();
    int peak = *it;
    return peak;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    int ans = ob.findPeakElement(a);
    cout << ans << "\n";
  }
  return 0;
}
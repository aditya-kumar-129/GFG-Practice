#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> findMissing(long long a[], long long b[], int n, int m)
  {
    map<long long, int> map;
    for (int i = 0; i < m; i++)
      map[b[i]]++;
    vector<long long> v;
    for (int i = 0; i < n; i++)
      if (map.find(a[i]) == map.end())
        v.push_back(a[i]);
    return v;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    long long a[n], b[m];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    vector<long long> ans;
    Solution ob;
    ans = ob.findMissing(a, b, n, m);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}
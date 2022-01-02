#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long getMin(long long A[], long long B[], long long n)
  {
    if (n == 1)
      return -1;
    vector<pair<long long, long long>> a, b;
    for (int i = 0; i < n; i++)
    {
      a.push_back(make_pair(A[i], i));
      b.push_back(make_pair(B[i], i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long int ans;
    if (a[0].second != b[0].second)
      ans = a[0].first + b[0].first;
    else
      ans = min(a[0].first + b[1].first, a[1].first + b[0].first);
    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    long long n, i;
    cin >> n;
    long long A[n + 1], B[n + 1];
    for (i = 0; i < n; i++)
      cin >> A[i];

    for (i = 0; i < n; i++)
      cin >> B[i];
    Solution ob;
    cout << ob.getMin(A, B, n) << endl;
  }
}
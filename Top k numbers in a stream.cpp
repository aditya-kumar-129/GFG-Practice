#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> kTop(int arr[], int n, int k)
  {
    vector<int> v;
    map<int, int> m;
    int max_freq = 0;
    for (int i = 0; i < n; i++)
    {
      m[arr[i]]++;
      if (max_freq < m[arr[i]])
        max_freq = m[arr[i]];
      int freq = max_freq;
      int j = 0;
      while (freq != 0 && j != k)
      {
        for (auto x : m)
        {
          if (x.second == freq)
          {
            v.push_back(x.first);
            j++;
            if (j == k)
              break;
          }
        }
        freq--;
      }
    }
    return v;
  }
};

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n, k;
    cin >> n >> k;
    int a[n];
    for (long long i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    vector<int> ans;
    ans = ob.kTop(a, n, k);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
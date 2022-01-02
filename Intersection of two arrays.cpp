#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int NumberofElementsInIntersection(int a[], int b[], int n, int m)
  {
    if (n > m)
      return NumberofElementsInIntersection(b, a, m, n);
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      if (s.find(b[i]) != s.end())
      {
        ans++;
        s.erase(b[i]); // now erase the element so that duplicate won't come
      }
    }
    return ans;
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
    int a[n], b[m];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    Solution ob;
    cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
  }
  return 0;
}

// Method 2 :-  Using Map

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
  unordered_map<int, int> mp;
  int count = 0;
  for (int i = 0; i < n; i++)
    mp[a[i]]++;
  for (int i = 0; i < m; i++)
  {
    if (mp.find(b[i]) != mp.end() && mp[b[i]] > 0)
    {
      count++;
      mp[b[i]] = 0; // now make the frequency of this element so that duplicate won't come
    }
  }
  return count;
}
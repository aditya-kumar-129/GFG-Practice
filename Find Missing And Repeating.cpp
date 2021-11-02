#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int *findTwoElement(int *arr, int n)
  {
    int *ans = new int[2];
    map<int, int> m;
    for (int i = 0; i < n; i++)
      m[arr[i]]++;
    for (auto it : m)
      if (it.second > 1)
        ans[0] = it.first;
    for (int i = 1; i < n + 1; i++)   // set {1, 2, …N} 
      if (m.find(i) == m.end())
        ans[1] = i;
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    auto ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
}
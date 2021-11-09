#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int rowWithMax1s(vector<vector<int>> v, int n, int m)
  {
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
      int count = 0;
      for (int j = 0; j < v[i].size(); j++)
        if (v[i][j] == 1)
          count++;
      if (count > max && count > 0)
      {
        max = count;
        index = i;
      }
    }
    return index;
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
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> arr[i][j];
    Solution ob;
    auto ans = ob.rowWithMax1s(arr, n, m);
    cout << ans << "\n";
  }
  return 0;
}
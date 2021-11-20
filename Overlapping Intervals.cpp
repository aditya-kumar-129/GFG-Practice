#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    vector<int> current = intervals[0];
    for (int i = 1; i < n; i++)
    {
      if (intervals[i][0] <= current[1])
        current[1] = max(intervals[i][1], current[1]);
      else
      {
        ans.push_back(current);
        current = intervals[i];
      }
    }
    ans.push_back(current);
    return ans;
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
    vector<vector<int>> Intervals(n);
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      Intervals[i].push_back(x);
      Intervals[i].push_back(y);
    }
    Solution obj;
    vector<vector<int>> ans = obj.overlappedInterval(Intervals);
    for (auto i : ans)
      for (auto j : i)
        cout << j << " ";
    cout << "\n";
  }
  return 0;
}
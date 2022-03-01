#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 1)
          ans[i][j] = 0, q.push({i, j});

    while (!q.empty())
    {
      int i = q.front().first;
      int j = q.front().second;

      if ((i - 1 >= 0) && ans[i][j] + 1 < ans[i - 1][j])
        ans[i - 1][j] = ans[i][j] + 1, q.push({i - 1, j});
      if ((j - 1 >= 0) && ans[i][j] + 1 < ans[i][j - 1])
        ans[i][j - 1] = ans[i][j] + 1, q.push({i, j - 1});
      if ((i + 1 < n) && ans[i][j] + 1 < ans[i + 1][j])
        ans[i + 1][j] = ans[i][j] + 1, q.push({i + 1, j});
      if ((j + 1 < m) && ans[i][j] + 1 < ans[i][j + 1])
        ans[i][j + 1] = ans[i][j] + 1, q.push({i, j + 1});
      q.pop();
    }
    return ans;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> grid[i][j];
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (auto i : ans)
    {
      for (auto j : i)
        cout << j << " ";
      cout << "\n";
    }
  }
  return 0;
}
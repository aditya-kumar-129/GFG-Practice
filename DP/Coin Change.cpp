#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int count(int c[], int n, int s)
  {
    int i, j;
    if (n == 0 || s == 0)
      return 1;
    vector<vector<long long int>> dp(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
      dp[i] = vector<long long int>(s + 1);
      for (int j = 0; j < s + 1; j++)
      {
        if (j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
      }
    }
    for (i = 1; i < n + 1; i++)
    {
      for (j = 1; j < s + 1; j++)
      {
        if (c[i - 1] <= j)
          dp[i][j] = dp[i - 1][j] + dp[i][j - c[i - 1]];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n][s];
  }
};
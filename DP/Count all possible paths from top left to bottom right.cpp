#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution
{
public:
  long long int numberOfPaths(int m, int n)
  {
    int count[m][n];
    for (int i = 0; i < m; i++)
      count[i][0] = 1;
    for (int j = 0; j < n; j++)
      count[0][j] = 1;
    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        count[i][j] = count[i - 1][j] % MOD + count[i][j - 1] % MOD;
    return count[m - 1][n - 1] % MOD;
  }
};

// Method:- 2
long long int numberOfPaths(int m, int n)
{
  long long dp[m][n];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] % MOD + dp[i][j - 1] % MOD;
    }
  return dp[m - 1][n - 1] % MOD;
}
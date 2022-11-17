#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestPalin(string S)
  {
    int n = S.size();
    int p = -1;
    string k = "";
    bool a[n][n];
    for (int g = 0; g < n; g++)
    {
      for (int i = 0, j = g; j < n; i++, j++)
      {
        if (g == 0)
          a[i][j] = true;
        else if (g == 1)
        {
          if (S[i] == S[j])
            a[i][j] = true;
          else
            a[i][j] = false;
        }
        else
        {
          if (S[i] == S[j] && a[i + 1][j - 1] == true)
            a[i][j] = true;
          else
            a[i][j] = false;
        }
        if (p < g && a[i][j] == true)
        {
          k = "";
          p = g;
          for (int t = i; t <= j; t++)
            k += S[t];
        }
      }
    }
    return k;
  }
};
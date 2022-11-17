#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lenOfLongSubarr(int A[], int N, int K)
  {
    int ln = 0, sum = 0;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
      sum += A[i];
      if (sum == K)
        ln = max(i + 1, ln);
      if (m.find(sum) == m.end())
        m[sum] = i;
      if (m.find(sum - K) != m.end())
        ln = max(ln, i - m[sum - K]);
    }
    return ln;
  }
};
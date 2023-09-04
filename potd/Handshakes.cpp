// https://www.youtube.com/watch?v=J3Mtaa0jv6s
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
  int count(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 2;i <= n;i += 2) {
      for (int j = 0;j <= i - 2;j += 2)
        dp[i] += dp[j] * dp[i - 2 - j];
    }
    return dp[n];
  }
};
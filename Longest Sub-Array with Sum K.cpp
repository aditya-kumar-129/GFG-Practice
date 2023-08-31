#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lenOfLongSubarr(int A[], int N, int K) {
    int len = 0, sum = 0;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
      sum += A[i];
      if (sum == K) len = max(i + 1, len);
      if (mp.find(sum) == mp.end()) mp[sum] = i;
      if (mp.find(sum - K) != mp.end()) len = max(len, i - mp[sum - K]);
    }
    return len;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long getMin(long long A[], long long B[], long long n) {
    if (n == 1) return -1;
    vector<pair<long long, long long>> a, b;
    for (int i = 0; i < n; i++) {
      a.push_back(make_pair(A[i], i));
      b.push_back(make_pair(B[i], i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long int ans;
    if (a[0].second != b[0].second) {
      ans = a[0].first + b[0].first;
    }
    else {
      ans = min(a[0].first + b[1].first, a[1].first + b[0].first);
    }
    return ans;
  }
};
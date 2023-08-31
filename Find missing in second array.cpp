#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<long long> findMissing(long long a[], long long b[], int n, int m) {
    map<long long, int> mp;
    for (int i = 0; i < m; i++) mp[b[i]]++;
    vector<long long> ans;
    for (int i = 0; i < n; i++) {
      if (mp.find(a[i]) == mp.end()) ans.push_back(a[i]);
    }
    return ans;
  }
};

// Method 2:- Using Set
vector<long long> findMissing(long long A[], long long B[], int N, int M) {
  set<int> s(B, B + M);
  vector<long long> ans;
  for (int i = 0;i < N;i++) {
    if (s.find(A[i]) == s.end()) ans.push_back(A[i]);
  }
  return ans;
}
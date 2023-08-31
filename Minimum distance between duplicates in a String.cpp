#include <bits/stdc++.h>
using namespace std;

int shortestDistance(string s, int n) {
  map<char, int> m;
  vector<int> v;
  int var;
  for (int i = 0; i < n; i++) {
    if (m.find(s[i]) != m.end()) {
      var = i - m[s[i]];
      m[s[i]] = i;
      v.push_back(var);
    }
    else m[s[i]] = i;
  }
  if (v.size() == 0) return -1;
  sort(v.begin(), v.end());
  return v[0] - 1;
}
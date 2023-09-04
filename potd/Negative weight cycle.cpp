#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
    vector<int> dis(n, 1e9);
    dis[0] = 0;
    for (int i = 0; i < n; i++) {
      for (auto itr : edges) {
        int u = itr[0], v = itr[1], wt = itr[2];
        dis[v] = min(dis[v], dis[u] + wt);
      }
    }
    for (auto itr : edges) {
      int u = itr[0], v = itr[1], wt = itr[2];
      if (dis[v] > dis[u] + wt) return 1;
    }
    return 0;
  }
};
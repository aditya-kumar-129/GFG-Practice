#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int isNegativeWeightCycle(int n, vector<vector<int>>edges)
  {
    vector<int> dis(n, 1e9);
    dis[0] = 0;
    for (int i = 0; i < n; i++)
    {
      for (auto itr : edges)
      {
        int u = itr[0];
        int v = itr[1];
        int wt = itr[2];
        dis[v] = min(dis[v], dis[u] + wt);
      }
    }
    for (auto itr : edges)
    {
      int u = itr[0];
      int v = itr[1];
      int wt = itr[2];
      if (dis[v] > dis[u] + wt)
        return 1;
    }
    return 0;
  }
};

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>edges;
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      edges.push_back({ x,y,z });
    }
    Solution obj;
    int ans = obj.isNegativeWeightCycle(n, edges);
    cout << ans << "\n";
  }
  return 0;
}
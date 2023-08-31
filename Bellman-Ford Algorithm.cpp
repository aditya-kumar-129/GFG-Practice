#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> bellman_ford(int V, vector<vector<int>> adj, int S) {
    vector<int> distance(V, 1e8);
    // Making the distance value of source node to 0
    distance[S] = 0;
    for (int i = 0; i < V - 1; i++) {
      for (auto it : adj) {
        int u = it[0], v = it[1], weight = it[2];
        if (distance[u] + weight < distance[v])
          distance[v] = distance[u] + weight;
      }
    }
    return distance;
  }
};
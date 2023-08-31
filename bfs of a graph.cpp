#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> visited(V, 0);  // Specifying size and initializing all values
    queue<int> q;
    q.push(0);
    while (q.size() > 0) {
      bfs.push_back(q.front());
      visited[q.front()] = 1;
      for (auto i = 0; i < adj[q.front()].size(); i++) {
        if (visited[adj[q.front()][i]] == 0) {
          q.push(adj[q.front()][i]);
          visited[adj[q.front()][i]] = 1;
        }
      }
      q.pop();
    }
    return bfs;
  }
};
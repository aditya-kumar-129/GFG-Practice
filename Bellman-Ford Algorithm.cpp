#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
  {
    vector<int> distance(V, 1e8);
    distance[S] = 0;      // Making the distance value of source node to 0
    for (int i = 0; i < V - 1; i++)
    {
      for (auto it : adj)
      {
        int u = it[0], v = it[1], weight = it[2];
        if (distance[u] + weight < distance[v])
          distance[v] = distance[u] + weight;
      }
    }
    return distance;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, E; // V:- No of vertex in the graph  // E:- No of edge in the graph
    cin >> V >> E;
    vector<vector<int>> adj;
    int i = 0;
    while (i++ < E)
    {
      int u, v, w; // w:- weight of the edge joing vertex u and vertex v
      cin >> u >> v >> w;
      vector<int> t1;
      t1.push_back(u);
      t1.push_back(v);
      t1.push_back(w);
      adj.push_back(t1);
    }
    int S; // S:-source vertex
    cin >> S;
    Solution obj;
    vector<int> res = obj.bellman_ford(V, adj, S);
    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
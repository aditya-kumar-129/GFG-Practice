#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    vector<int> result;
    bool flag[V] = { false };
    for (int i = 0;i < V;i++)
      result.push_back(INT_MAX);

    result[S] = 0;
    for (int i = 0; i < V;i++) {
      int u = mindis(flag, result);
      flag[u] = true;
      for (int j = 0; j < adj[u].size(); j++)
        if (!flag[adj[u][j][0]] && result[u] != INT_MAX && result[adj[u][j][0]] > adj[u][j][1] + result[u])
          result[adj[u][j][0]] = adj[u][j][1] + result[u];
    }
    return result;
  }
  int mindis(bool inset[], vector<int> result) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < result.size(); i++)
      if (!inset[i] && result[i] < min)
        min = result[i], min_index = i;
    return min_index;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--) {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i < E) {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
      i++;
    }
    int S;
    cin >> S;
    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}

// Method 2 :- Using priority queue

class Solution
{
public:
  vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
  {
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    vector<int> dist(n, INT_MAX);
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
      pair<int, int> cur = pq.top();
      pq.pop();
      int node = cur.second;
      int currWeight = cur.first;

      for (auto it : adj[node]) {
        int nextNode = it[0];
        int nextWeight = it[1];

        if (currWeight + nextWeight < dist[nextNode]) {
          dist[nextNode] = currWeight + nextWeight;
          pq.push(make_pair(dist[nextNode], nextNode));
        }
      }
    }
    return dist;
  }
};
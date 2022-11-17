#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to return a list containing the DFS traversal of the graph.
  void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans)
  {
    ans.push_back(node);

    for (int neigh : adj[node])
    {
      if (visited[neigh] == 0)
      {
        visited[neigh] = 1;
        dfs(neigh, visited, adj, ans);
      }
    }
  }

  // Function to return a list containing the DFS traversal of the graph.
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
      if (visited[i] == 0)
      {
        visited[i] = 1;
        dfs(i, visited, adj, ans);
      }
    }
    return ans;
  }
};
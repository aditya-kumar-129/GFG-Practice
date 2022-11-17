#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
  {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> intermediate_pair;
    int second_term;
    for (auto it : intervals)
    {
      if (intermediate_pair.size() == 0)
      {
        intermediate_pair.push_back(it[0]);
        second_term = it[1];
      }
      else if (second_term >= it[0])
      {
        if (second_term > it[1])
          second_term = second_term;
        else
          second_term = it[1];
      }
      else
      {
        intermediate_pair.push_back(second_term);
        ans.push_back(intermediate_pair);
        intermediate_pair.clear();
        intermediate_pair.push_back(it[0]);
        second_term = it[1];
      }
    }
    intermediate_pair.push_back(second_term);
    ans.push_back(intermediate_pair);
    return ans;
  }
};

int main() 
{
  int tc;
  cin >> tc;
  while (tc--) 
  {
    int n;
    cin >> n;
    vector<vector<int>>Intervals(n);
    for (int i = 0; i < n; i++) 
    {
      int x, y;
      cin >> x >> y;
      Intervals[i].push_back(x);
      Intervals[i].push_back(y);
    }
    Solution obj;
    vector<vector<int>> ans = obj.overlappedInterval(Intervals);
    for (auto i : ans) 
      for (auto j : i) 
        cout << j << " ";
    cout << "\n";
  }
  return 0;
}

// Method 2 

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
{
  vector<vector<int>> ans;
  sort(intervals.begin(), intervals.end());
  ans.push_back(intervals[0]);
  for (int i = 1;i < intervals.size();i++) 
  {
    if (ans[ans.size() - 1][1] >= intervals[i][0]) 
      ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
    else 
      ans.push_back(intervals[i]);
  }
  return ans;
}
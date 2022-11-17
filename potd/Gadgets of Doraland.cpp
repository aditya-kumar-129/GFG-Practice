#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool comp(pair<int, int>a, pair<int, int>b)
  {
    if (a.second == b.second)
      return a.first > b.first;
    else
      return a.second > b.second;
  }
  vector<int> TopK(vector<int>& array, int k)
  {
    map<int, int>mp;
    for (int i = 0;i < array.size();i++)
      mp[array[i]]++;
    vector<pair<int, int>>v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);
    vector<int>ans;
    for (int i = 0;i < k;i++)
      ans.push_back(v[i].first);
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n;
    vector<int>array(n);
    for (int i = 0; i < n; i++)
      cin >> array[i];
    cin >> k;
    Solution obj;
    vector<int> result = obj.TopK(array, k);
    for (int i = 0; i < result.size();i++)
      cout << result[i] << " ";
    cout << "\n";
  }
  return 0;
}  

// Method 2 :- Using Priority queue
class Solution {
public:
  vector<int> TopK(vector<int>& array, int k)
  {
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    map<int, int> mp;
    for (int i = 0;i < array.size();i++)
      mp[array[i]]++;
    for (auto it : mp)
      pq.push({ it.second,it.first });
    for (int i = 0;i < k;i++)
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};
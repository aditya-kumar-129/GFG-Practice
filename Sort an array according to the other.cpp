#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
  {
    vector<int> temp;
    bool flag = false;
    map<int, int> m;
    sort(A1.begin(), A1.end());
    for (int i = 0; i < N; i++)
      m[A1[i]]++;
    for (int i = 0; i < M; i++)
    {
      if (m.find(A2[i]) != m.end() && m[A2[i]] != -1)
        for (int j = 0; j < m[A2[i]]; j++)
          temp.push_back(A2[i]);
      m[A2[i]] = -1;
      flag = true;
    }
    for (int i = 0; i < N; i++ && flag)
    {
      if (m.find(A1[i]) != m.end() && m[A1[i]] != -1)
        for (int j = 0; j < m[A1[i]]; j++)
          temp.push_back(A1[i]);
      m[A1[i]] = -1;
    }
    if (!flag)
      for (int i = 0; i < A1.size(); i++)
        temp.push_back(A1[i]);
    return temp;
  }
};

// In below method we get to know how to push more than one element to a vector simultaneously
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
  vector<int> ans;
  map<int, int> m;
  for (auto x : A1)
    m[x]++;
  for (auto temp : A2)
  {
    auto x = m.find(temp);
    vector<int> v(x->second, temp);
    ans.insert(ans.end(), v.begin(), v.end());
    m.erase(temp);
  }
  for (auto x : m)
  {
    vector<int> v(x.second, x.first);
    ans.insert(ans.end(), v.begin(), v.end());
  }
  return ans;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> PosNegPair(int a[], int n)
  {
    vector<int> v, ans;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      if (a[i] < 0)
        v.push_back(a[i]);
      else
        m[a[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
      if (m.find(abs(v[i])) != m.end())
      {
        ans.push_back(v[i]);
        ans.push_back(abs(v[i]));
        m[abs(v[i])]--;
        if (m[abs(v[i])] == 0)
          m.erase(abs(v[i]));
      }
    }
    return ans;
  }
};

// Other way of solving the problem is :-
/*
Few articles concept that has been used here is:- 
https://www.geeksforgeeks.org/map-count-function-in-c-stl/
*/
vector<int> PosNegPair(int a[], int n)
{
  map<int, int> pos, neg;
  for (int i = 0; i < n; ++i)
  {
    if (a[i] > 0)
      pos[a[i]]++;
    else
      neg[abs(a[i])]++;
  }
  vector<int> res;
  for (auto x : pos)
  {
    // The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container else 0 if the element with key K is not present in the container.
    if (neg.count(x.first))
    {
      // finding the minimum of the frequency of the two map which means that only that much pair can be formed
      int elements = min(x.second, neg[x.first]);
      for (int i = 0; i < elements; ++i)
      {
        res.push_back(-x.first);
        res.push_back(x.first);
      }
    }
  }
  return res;
}
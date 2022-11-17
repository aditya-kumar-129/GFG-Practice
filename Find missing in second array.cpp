#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> findMissing(long long a[], long long b[], int n, int m)
  {
    map<long long, int> map;
    for (int i = 0; i < m; i++)
      map[b[i]]++;
    vector<long long> v;
    for (int i = 0; i < n; i++)
      if (map.find(a[i]) == map.end())
        v.push_back(a[i]);
    return v;
  }
};

// Method 2:- Using Set
vector<long long> findMissing(long long A[], long long B[],int N, int M)
{
  unordered_set<int> us(B, B + M);
  vector<long long> ans;
  for (int i = 0;i < N;i++)
    if (us.find(A[i]) == us.end()) 
      ans.push_back(A[i]);
  return ans;
}
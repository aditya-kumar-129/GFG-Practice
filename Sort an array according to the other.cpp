#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
    vector<int> temp;
    bool flag = false;
    map<int, int> mp;
    sort(A1.begin(), A1.end());
    for (int i = 0; i < N; i++) mp[A1[i]]++;
    for (int i = 0; i < M; i++) {
      if (mp.find(A2[i]) != mp.end() && mp[A2[i]] != -1) {
        for (int j = 0; j < mp[A2[i]]; j++) temp.push_back(A2[i]);
      }
      mp[A2[i]] = -1;
      flag = true;
    }
    for (int i = 0; i < N; i++ && flag) {
      if (mp.find(A1[i]) != mp.end() && mp[A1[i]] != -1) {
        for (int j = 0; j < mp[A1[i]]; j++) temp.push_back(A1[i]);
      }
      mp[A1[i]] = -1;
    }
    if (!flag) {
      for (int i = 0; i < A1.size(); i++) temp.push_back(A1[i]);
    }
    return temp;
  }
};

// In below method we get to know how to push more than one element to a vector simultaneously
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
  vector<int> ans;
  map<int, int> mp;
  for (auto x : A1) mp[x]++;
  for (auto temp : A2) {
    auto x = mp.find(temp);
    vector<int> v(x->second, temp);
    ans.insert(ans.end(), v.begin(), v.end());
    mp.erase(temp);
  }
  for (auto x : mp) {
    vector<int> v(x.second, x.first);
    ans.insert(ans.end(), v.begin(), v.end());
  }
  return ans;
}
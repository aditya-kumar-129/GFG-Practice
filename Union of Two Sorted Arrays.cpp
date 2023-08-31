#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(arr1[i]);
    for (int i = 0; i < m; i++) s.insert(arr2[i]);
    vector<int> ans;
    for (auto it : s) ans.push_back(it);
    return ans;
  }
};
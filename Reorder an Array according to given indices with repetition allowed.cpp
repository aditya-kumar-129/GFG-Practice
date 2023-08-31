#include <bits/stdc++.h>
using namespace std;

void reorder(vector<int>& arr, vector<int>& index) {
  vector<int> ans;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    ans.insert(ans.begin() + index[i], arr[i]);
  }
}
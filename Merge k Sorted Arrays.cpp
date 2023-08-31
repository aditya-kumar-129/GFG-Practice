#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
// Complexity Analysis :
// Time Complexity : O(n *k *log(n *k)).since resulting array is of N *k size.
// Space Complexity : O(n *k), The output array is of size n *k.
class Solution {
public:
  vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    vector<int> v;
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++)
        v.push_back(arr[i][j]);
    }
    sort(v.begin(), v.end());
    return v;
  }
};
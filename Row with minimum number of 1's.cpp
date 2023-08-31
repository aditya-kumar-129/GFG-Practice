// Question Link :- https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minRow(int n, int m, vector<vector<int>> matrix) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
      int temp = 0;
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 1) temp++;
      }
      vec.push_back({ temp, i + 1 });
    }
    sort(vec.begin(), vec.end());
    return vec[0].second;
  }
};
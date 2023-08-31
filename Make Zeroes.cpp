// Question Link :- https://practice.geeksforgeeks.org/problems/make-zeroes4042/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void MakeZeros(vector<vector<int> >& matrix) {
    vector<vector<int>> temp = matrix;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0;i < n;i++) {
      for (int j = 0;j < m;j++) {
        if (temp[i][j] == 0) {
          if (i + 1 < n) matrix[i][j] += temp[i + 1][j], matrix[i + 1][j] = 0;
          if (i - 1 >= 0) matrix[i][j] += temp[i - 1][j], matrix[i - 1][j] = 0;
          if (j + 1 < m) matrix[i][j] += temp[i][j + 1], matrix[i][j + 1] = 0;
          if (j - 1 >= 0) matrix[i][j] += temp[i][j - 1], matrix[i][j - 1] = 0;
        }
      }
    }
  }
};
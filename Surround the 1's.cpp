// Question Link :- https://practice.geeksforgeeks.org/problems/surround-the-1s2505/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int Count(vector<vector<int> >& matrix) {
    int n = matrix.size(), m = matrix[0].size(), count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == 1) {
          int temp = 0; // Reset temp for each new cell
          if (i - 1 >= 0 && matrix[i - 1][j] == 0) temp++;
          if (i + 1 < n && matrix[i + 1][j] == 0) temp++;
          if (j - 1 >= 0 && matrix[i][j - 1] == 0) temp++;
          if (j + 1 < m && matrix[i][j + 1] == 0) temp++;
          if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] == 0) temp++;
          if (i - 1 >= 0 && j + 1 < m && matrix[i - 1][j + 1] == 0) temp++;
          if (i + 1 < n && j - 1 >= 0 && matrix[i + 1][j - 1] == 0) temp++;
          if (i + 1 < n && j + 1 < m && matrix[i + 1][j + 1] == 0) temp++;
          if (temp % 2 == 0 && temp != 0) count++;
        }
      }
    }
    return count;
  }
};
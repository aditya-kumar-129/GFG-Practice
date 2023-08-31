#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rowWithMax1s(vector<vector<int>> v, int n, int m) {
    int max = INT_MIN, index = -1;
    for (int i = 0; i < v.size(); i++) {
      int count = 0;
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == 1) count++;
      }
      if (count > max && count > 0) {
        max = count;
        index = i;
      }
    }
    return index;
  }
};
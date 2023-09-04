#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int eulerPath(int N, vector<vector<int>> graph) {
    int oddCount = 0, evenCount = 0;
    for (auto temp : graph) {
      int count = 0;
      for (auto it : temp) {
        if (it == 1) count++;
      }
      if (count % 2 == 0) evenCount++;
      else oddCount++;
    }
    if (oddCount == 2 || oddCount == 0 && evenCount >= 0) return 1;
    else return 0;
  }
};
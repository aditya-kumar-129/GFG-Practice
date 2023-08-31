#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPalin(string str) {
    int n = str.size(), p = -1;
    string ans = "";
    bool a[n][n];
    for (int g = 0; g < n; g++) {
      for (int i = 0, j = g; j < n; i++, j++) {
        if (g == 0) a[i][j] = true;
        else if (g == 1) {
          if (str[i] == str[j]) a[i][j] = true;
          else a[i][j] = false;
        }
        else {
          if (str[i] == str[j] && a[i + 1][j - 1] == true) a[i][j] = true;
          else a[i][j] = false;
        }
        if (p < g && a[i][j] == true) {
          ans = "";
          p = g;
          for (int t = i; t <= j; t++) ans += str[t];
        }
      }
    }
    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int chk(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] > s[i + 1]) return 0;
    }
    return 1;
  }

  int find(int n) {
    while (n) {
      if (chk(n)) return n;
      n--;
    }
  }
};
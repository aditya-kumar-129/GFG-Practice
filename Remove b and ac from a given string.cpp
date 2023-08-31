#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string stringFilter(string str) {
    string res = "";
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'b') continue;
      if (str[i] == 'a' && str[i + 1] == 'c' && i != str.length()) {
        i++;
        continue;
      }
      res += str[i];
    }
    return res;
  }
};
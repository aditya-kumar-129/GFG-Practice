#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string temp = "", ans = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '.') temp += s[i];
      else {
        reverse(temp.begin(), temp.end());
        ans += temp;
        ans += '.';
        temp = "";
      }
    }
    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
  }
};
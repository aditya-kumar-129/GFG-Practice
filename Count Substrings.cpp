#include <bits/stdc++.h>
using namespace std;

// Youtube Video Link :-  https://youtu.be/gEHq-2MBhts

class Solution {
public:
  int countSubstr(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') count++;
    }
    return (count * (count - 1)) / 2;
  }
};

// Method 2:-
int countSubstr(string s) {
  int ans = 0;
  map<int, int> m;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      ans += m[s[i]];
      m[s[i]]++;
    }
  }
  return ans;
}

// Method 3 
int countSubstr(string s) {
  int x = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1') x++;
  }
  int count = 0;
  for (int i = 1; i < x; i++) count = count + i;
  return count;
}
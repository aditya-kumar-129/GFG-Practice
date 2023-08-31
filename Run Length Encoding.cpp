#include <bits/stdc++.h>
using namespace std;

string encode(string s) {
  int c = 1;
  for (int i = 0;i < s.length();i++) {
    if (s[i] == s[i + 1]) c++;
    else {
      cout << s[i] << c;
      c = 1;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int isPalindrome(string str) {
    int low = 0, high = str.length() - 1;
    while (high > low) {
      if (str[low++] != str[high--]) return 0;
    }
    return 1;
  }
};
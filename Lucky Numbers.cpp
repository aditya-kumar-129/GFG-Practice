#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isLucky(int n) {
    int deleteevery = 2;
    while (n >= deleteevery) {
      if (n % deleteevery == 0) return false;
      n -= (n / deleteevery);
      deleteevery++;
    }
    return true;
  }
};
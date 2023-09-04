#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSquare(int b) {
    if (b & 1) {
      b--;
      return ((b * b) - (2 * b)) / 8;
    }
    else
      return ((b * b) - (2 * b)) / 8;
  }
};
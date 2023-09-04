#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
  int sum(int a, int b) {
    while (b) {
      int carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
    return a;
  }
};
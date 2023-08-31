#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getSingle(int a[], int n) {
    // Logic:- since we know that the XOR of same bits in a xor opeartion results zero so when the other number occurs even times its effect gets cancelled and only the one that has occured odd number of times get stored in the sum variable
    int sum = 0;
    for (int i = 0; i < n; i++) sum ^= a[i];
    return sum;
  }
};

// Brute Force Approach
class Solution {
public:
  int getSingle(int a[], int n)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
      m[a[i]]++;
    for (auto it : m)
      if (it.second % 2 == 1)
        return it.first;
    return 0;
  }
};

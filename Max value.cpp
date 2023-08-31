#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxVal(int nums[], int n) {
    for (int i = 0; i < n; i++) nums[i] = nums[i] - i;
    sort(nums, nums + n);
    return nums[n - 1] - nums[0];
  }
};
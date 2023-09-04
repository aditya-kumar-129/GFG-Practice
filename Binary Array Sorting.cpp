// Question Link :- https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// WHEN USED INBUILT sort() FUNCTION THEN IT GIVES TLE AS INBUILT sort() HAS A TIME COMPLEXITY OF nlog(n);
class Solution {
public:
  vector<int> SortBinaryArray(vector<int> nums) {
    int count_zero = 0, count_one = 0;
    for (auto it : nums) {
      if (it == 1) count_one++;
      else count_zero++;
    }
    vector<int> ans;
    for (int i = 0; i < count_zero; i++) ans.push_back(0);
    for (int i = 0; i < count_one; i++) ans.push_back(1);
    return ans;
  }
};
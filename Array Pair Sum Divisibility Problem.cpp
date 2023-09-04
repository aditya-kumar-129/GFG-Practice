// Question Link :- https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPair(vector<int> nums, int k) {
    int n = nums.size();
    if (n % 2 == 1) return false;  // odd number of elements can not be paired.
    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[nums[i] % k]++;
    for (int i = 0; i < n; i++) {
      int remainder = nums[i] % k;
      // When the pair contains the same number and whose sum is divisible by k.
      if (2 * remainder == k) {
        if (mp[remainder] % 2 == 1) return false;
      }
      // Pair in which both the elements contain the same number as that of k
      else if (remainder == 0) {
        if (mp[remainder] % 2 == 1) return false;
      }
      else if (mp[remainder] != mp[k - remainder]) return false;
    }
    return true;
  }
};

// Method 2:-
bool canPair(vector<int> nums, int k) {
  int n = nums.size();
  if (n % 2 == 1) return false;
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[nums[i] % k]++;
  if (mp[0] % 2 != 0) return false;
  for (int i = 1; i < k; i++) {
    if (mp[i] != mp[k - i]) return false;
  }
  return true;
}

// Method 3:-
bool canPair(vector<int> nums, int k) {
  map<int, int> mp;
  for (int i = 0; i < nums.size(); i++)
    mp[((nums[i] % k) + k) % k]++;
  for (auto it : mp) {
    int key = it.first;
    if (key == 0) {
      if (it.second % 2 != 0) return false;
      else if (mp[key] != mp[k - key]) return false;
    }
  }
  return true;
}
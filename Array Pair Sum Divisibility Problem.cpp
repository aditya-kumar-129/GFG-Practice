#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPair(vector<int> nums, int k) {
    int n = nums.size();
    if (n % 2 == 1) return false;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[nums[i] % k]++;
    for (int i = 0; i < n; i++) {
      int rem = nums[i] % k;
      if (2 * rem == k) {
        if (mp[rem] % 2 == 1) return false;
      }
      else if (rem == 0) {
        if (mp[rem] % 2 == 1) return false;
      }
      else if (mp[rem] != mp[k - rem]) return false;
    }
    return true;
  }
};

// Method 2:-
bool canPair(vector<int> nums, int k) {
  int n = nums.size();
  if (n % 2 == 1) return false;
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++) freq[nums[i] % k]++;
  if (freq[0] % 2 != 0) return false;
  for (int i = 1; i < k; i++) {
    if (freq[i] != freq[k - i]) return false;
  }
  return true;
}

// Method 3:-
bool canPair(vector<int> nums, int k) {
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
    m[((nums[i] % k) + k) % k]++;
  for (auto it : m) {
    int key = it.first;
    if (key == 0) {
      if (it.second % 2 != 0) return false;
      else if (m[key] != m[k - key]) return false;
    }
  }
  return true;
}
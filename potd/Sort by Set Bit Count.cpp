#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortBySetBitCount(int arr[], int n) {
    map<int, vector<int>> mp;
    for (int i = 0;i < n;i++) {
      int count = __builtin_popcount(arr[i]);
      mp[count].push_back(arr[i]);
    }
    int i = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
      for (auto etr : it->second) arr[i++] = etr;
    }
  }
};

// Method 2 :- 
class Solution {
public:
  static bool comp(int a, int b) {
    return __builtin_popcount(a) > __builtin_popcount(b);
  }
  void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr + n, comp);
  }
};
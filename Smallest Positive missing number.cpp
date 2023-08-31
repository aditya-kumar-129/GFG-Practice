#include <bits/stdc++.h>
using namespace std;
// How to get the maximum element in the unordered set is important otherwise all are easy

class Solution {
public:
  int missingNumber(int arr[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++) s.insert(arr[i]);
    int a = *max_element(s.begin(), s.end());
    for (int i = 1; i <= a; i++) {
      if (s.find(i) == s.end()) return i;
    }
    return a + 1;
  }
};
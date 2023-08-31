#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int equilibriumPoint(long long arr[], int n) {
    int sum = accumulate(arr, arr + n, 0);
    int left_sum = 0;
    for (int i = 0; i < n; i++) {
      if (left_sum == sum - arr[i]) return i + 1;
      left_sum += arr[i];
      sum -= arr[i];
    }
    return -1;
  }
};
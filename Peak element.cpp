#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int peakElement(int arr[], int n) {
    int peak = -1;
    if (arr[0] > arr[1]) peak = 0;
    if (arr[n - 1] > arr[n - 2]) peak = n - 1;

    for (int i = 0; i < n; i++) {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        peak = i;
      }
    }
    return peak;
  }
};
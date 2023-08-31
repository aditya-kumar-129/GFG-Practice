#include <bits/stdc++.h>
using namespace std;

// Two Pointers Algorithm
// OPTIMUM SOLUTION
class Solution {
public:
  bool findTriplets(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++) {
      int left = i + 1, right = n - 1;
      while (left < right) {
        if (arr[left] + arr[right] + arr[i] == 0) return true;
        else if (arr[left] + arr[right] + arr[i] < 0) left++;
        else right--;
      }
    }
    return false;
  }
};
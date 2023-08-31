#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rearrange(long long* arr, int n) {
    int max_idx = n - 1, min_idx = 0, max_elem = arr[n - 1] + 1;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        arr[i] += (arr[max_idx--] % max_elem) * max_elem;
      }
      else {
        arr[i] += (arr[min_idx++] % max_elem) * max_elem;
      }
    }
    for (int i = 0; i < n; i++) arr[i] = arr[i] / max_elem;
  }
};

// A simpler approach will be to observe indexing positioning of maximum elements and minimum elements. The even index stores maximum elements and the odd index stores the minimum elements. With every increasing index, the maximum element decreases by one and the minimum element increases by one.
// This approach is only valid when elements of given sorted array are consecutive i.e., vary by one unit.

void rearrange(int arr[], int n) {
  int max_ele = arr[n - 1];
  int min_ele = arr[0];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) arr[i] = max_ele--;
    else arr[i] = min_ele++;
  }
}
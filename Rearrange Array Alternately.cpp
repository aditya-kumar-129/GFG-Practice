#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rearrange(long long* arr, int n) {
    int maxIndex = n - 1, minIndex = 0, max_elem = arr[n - 1] + 1;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        arr[i] += (arr[maxIndex--] % max_elem) * max_elem;
      }
      else {
        arr[i] += (arr[minIndex++] % max_elem) * max_elem;
      }
    }
    for (int i = 0; i < n; i++) arr[i] = arr[i] / max_elem;
  }
};


// Brute Force Approach
class Solution {
public:
  void rearrange(long long* arr, int n) {
    vector<long long> mini, maxi;
    int mid;
    if (n % 2 == 0) mid = n / 2;
    else mid = (n + 1) / 2;
    for (int i = 0; i < mid; i++) mini.push_back(arr[i]);
    for (int i = mid; i < n; i++) maxi.push_back(arr[i]);
    reverse(maxi.begin(), maxi.end());
    int i = 0, j = 0, k = 0;
    while (i < maxi.size() && j < mini.size()) {
      arr[k++] = maxi[i++];
      arr[k++] = mini[j++];
    }
    while (i < maxi.size()) arr[k++] = maxi[i++];
    while (j < mini.size()) arr[k++] = mini[j++];
  }

};
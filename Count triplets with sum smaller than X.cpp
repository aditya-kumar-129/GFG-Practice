#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countTriplets(long long arr[], int n, long long sum) {
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (arr[i] + arr[j] + arr[k] >= sum) k--;
        else {
          // Refere the below youtube video:- 
          // https://youtu.be/fLHOkJHE-NI
          ans += (k - j);
          j++;
        }
      }
    }
    return ans;
  }
};
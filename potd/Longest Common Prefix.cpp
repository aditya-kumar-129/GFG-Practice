#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string LCP(string arr[], int n) {
    sort(arr, arr + n);
    string ans = "";
    int min_len = min(arr[0].size(), arr[n - 1].size());
    string first = arr[0];
    string last = arr[n - 1];
    for (int i = 0;i < min_len;i++) {
      if (first[i] != last[i]) break;
      ans += first[i];
    }
    if (ans == "") return "-1";
    return ans;
  }
};
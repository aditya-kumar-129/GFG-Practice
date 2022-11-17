#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string LCP(string ar[], int n)
  {
    sort(ar, ar + n);
    string ans = "";
    int min_len = min(ar[0].size(), ar[n - 1].size());
    string first = ar[0];
    string last = ar[n - 1];
    for (int i = 0;i < min_len;i++)
    {
      if (first[i] != last[i])
        break;
      ans += first[i];
    }
    if (ans == "")
      return "-1";
    return ans;
  }
};
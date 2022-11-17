#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long karyTree(int k, int m) {
    // WHY CAN"T we use pow inbuilt function here
    long long ans = 1;
    for (int i = 1; i <= m; i++)
      ans = (ans * k) % 1000000007;
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, m;
    cin >> k >> m;
    Solution ob;
    cout << ob.karyTree(k, m) << endl;
  }
  return 0;
}  


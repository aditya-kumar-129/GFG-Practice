#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPosition(int n)
  {
    int totalSetBits = __builtin_popcount(n);
    if (totalSetBits > 1 || totalSetBits == 0)
      return -1;
    else
      return log2(n) + 1;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.findPosition(N) << endl;
  }
  return 0;
}  

// Method 2 :- using builtin ffs()

class Solution {
public:
  int findPosition(int n)
  {
    int totalSetBits = __builtin_popcount(n);
    if (totalSetBits > 1 || totalSetBits == 0)
      return -1;
    else
      return ffs(n);
  }
};
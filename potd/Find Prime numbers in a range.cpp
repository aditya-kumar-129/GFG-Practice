#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> primeRange(int m, int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= n; p++)
      if (prime[p] == true)
        for (int i = p * p; i <= n; i += p)
          prime[i] = false;
    vector<int> ans;
    for (int i = m;i <= n;i++)
      if (prime[i])
        ans.push_back(i);
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M, K;
    cin >> M >> N;
    Solution ob;
    vector<int> ans = ob.primeRange(M, N);
    for (auto u : ans) cout << u << " ";
    cout << "\n";
  }
}
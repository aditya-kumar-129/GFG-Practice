#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void frequencyCount(vector<int>& input, int n, int P) {
    for (int i = 0; i < n; i++) input[i]--;
    for (int i = 0; i < n; i++) input[input[i] % n] += n;
    for (int i = 0; i < n; i++) {
      if (input[i] / n)
        cout << "Element " << (i + 1) << " occurs " << input[i] / n << " times" << endl;
      // Changing the element back to original value
      input[i] = input[i] % n + 1;
    }
  }
};

// BRUTE FORCE APPROACH
void frequencyCount(vector<int>& arr, int N, int P) {
  map<int, int> mp;
  for (int i = 0; i < N; i++) mp[arr[i]]++;
  for (int i = 0; i < N; i++) {
    auto it = mp.find(i + 1);
    if (it != mp.end()) arr[i] = it->second;
    else arr[i] = 0;
  }
}
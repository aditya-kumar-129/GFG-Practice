#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countWords(string arr[], int n) {
    map<string, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for (auto it : mp) {
      if (it.second == 2) count++;
    }
    return count;
  }
};
#include <bits/stdc++.h>
using namespace std;

//upper_bound() is a standard library function in C++ which returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
// https://www.geeksforgeeks.org/upper_bound-in-cpp/

vector<long long> find(vector<long long> a, vector<long long> b, vector<long long> q) {
  vector<long long> ans;
  sort(b.begin(), b.end());
  for (auto it : q) {
    long long ind = it, n = a[ind];
    long long k = upper_bound(b.begin(), b.end(), n) - b.begin();
    ans.push_back(k);
  }
  return ans;
}
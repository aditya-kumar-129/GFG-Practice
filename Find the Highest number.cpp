#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& a) {
    int start = 0, end = a.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1]) return a[mid];
      else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1]) start = mid + 1;
      else end = mid - 1;
    }
  }
};

// Method 2:- Using for loop 
// Brute force approach
int findPeakElement(vector<int>& a) {
  for (int i = 0;i < a.size() - 1;i++) {
    if (a[i + 1] < a[i]) return a[i];
  }
  return a[a.size() - 1];
}

// Method 2:- Using while loop 
// Brute force approach
int findPeakElement(vector<int>& a) {
  int n = a.size(), i = 0;
  while (a[i] < a[i + 1] && i < n - 1) i++;
  return a[i];
}

// Method 3:- Brute force approach
int findPeakElement(vector<int>& a) {
  sort(a.begin(), a.end());
  auto it = --a.end();
  int peak = *it;
  return peak;
}
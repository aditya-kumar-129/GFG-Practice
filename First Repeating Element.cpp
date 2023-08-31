#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstRepeated(int arr[], int n) {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) m[arr[i]]++;
    for (int i = 0; i < n; i++) {
      if (m[arr[i]] > 1) return i + 1;
    }
    return -1;
  }
};

// Method 2:-  Using Set STL
int firstRepeated(int arr[], int n) {
  int index = -1;
  unordered_set<int> s;
  // WARNING:- HERE WE TRAVERSE FROM BACKWARD as we have to tell the minimum index value which has ocuured 
  for (int i = n - 1; i >= 0; i--) {
    if (s.find(arr[i]) != s.end()) index = i;
    else s.insert(arr[i]);
  }
  if (index == -1) return index;
  else return index + 1;
}
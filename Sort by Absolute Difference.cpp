// Question Link :- https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortABS(int arr[], int n, int x) {
    stable_sort(arr, arr + n, [x](int a, int b) {
      if (abs(a - x) < abs(b - x)) return true;
      else return false;
      });
  }
};

// I don't know why the below code is not working
class Solution {
public:
  static bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
  }
  void sortABS(int arr[], int n, int k) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      v.push_back({ abs(arr[i] - k), arr[i] });
    }
    sort(v.begin(), v.end(), compare);
    int i = 0;
    for (auto it : v) arr[i++] = it.second;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int kthSmallest(int arr[], int l, int r, int k) {
    sort(arr, arr + r + 1);
    return arr[k - 1];
  }
};

// this problem can also be solved using PRIORITY QUEUE
int kthSmallest(int arr[], int l, int r, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = l; i <= r; i++) pq.push(arr[i]);
  for (int i = 0; i < k - 1; i++) pq.pop();
  return pq.top();
}

int kthSmallest(int arr[], int l, int r, int k) {
  priority_queue<int> pq;
  for (int i = l; i <= r; i++) {
    pq.push(arr[i]);
    if (pq.size() > k) pq.pop();
  }
  return pq.top();
}

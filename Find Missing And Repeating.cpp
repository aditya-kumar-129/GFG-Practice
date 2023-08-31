#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int* findTwoElement(int* arr, int n) {
    int ans[] = { -1,-1 };
    // Finding the duplicate number
    for (int i = 0; i < n; ++i) {
      if (arr[abs(arr[i]) - 1] > 0)
        arr[(abs(arr[i])) - 1] = -arr[abs(arr[i]) - 1];
      else
        ans[0] = abs(arr[i]);
    }
    // Finding the missing number
    for (int i = 0; i < n; ++i) {
      if (arr[i] > 0) {
        ans[1] = i + 1;
        break;
      }
    }
    int* p = ans;
    return p;
  }
};

// Method 2:- OPTIMISED SOLUTION
// Time complexity:- O(n)
// Space Complexity :- O(1)
int* findTwoElement(int* arr, int n) {
  int* ans = new int(2);
  for (int i = 0;i < n;i++) arr[i] = arr[i] - 1;
  for (int i = 0;i < n; i++) arr[arr[i] % n] += n;
  for (int i = 0;i < n;i++) {
    arr[i] /= n;
    if (arr[i] == 2) ans[0] = i + 1;
    if (arr[i] == 0) ans[1] = i + 1;
  }
  return ans;
}

// Method 3 :- 
// Time complexity:- O(nlogn)
// Space Complexity :- O(1)

int* findTwoElement(int* nums, int n) {
  int* res = new int[2];
  sort(nums, nums + n);
  int temp = 1;
  for (int i = 0;i < n;i++) {
    // Finding the duplicate number
    if (nums[i] == nums[i + 1]) res[0] = nums[i];
    // Finding the missing number
    if (nums[i] == temp) temp++;
  }
  res[1] = temp;
  return res;
}

// Method:- 4
// Time complexity:- O(n)
// Space Complexity :- O(n)
int* findTwoElement(int* arr, int n) {
  int* ans = new int[2];
  map<int, int> m;
  for (int i = 0; i < n; i++) m[arr[i]]++;
  // Finding the duplicate number
  for (auto it : m) {
    if (it.second > 1) ans[0] = it.first;
  }
  // Finding the missing number
  // set {1, 2, …N} 
  for (int i = 1; i < n + 1; i++) {
    if (m.find(i) == m.end()) ans[1] = i;
  }
  return ans;
}
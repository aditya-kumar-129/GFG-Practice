#include <bits/stdc++.h>
using namespace std;

// OPTIMISED APPROACH
//Time Complexity is O(32.n) = O(n)
//Space Complexity :- O(1)
class Solution {
public:
  int singleElement(int arr[], int n) {
    int result = 0;
    for (int i = 0;i < 32;i++) {
      int count = 0;
      for (int j = 0;j < n;j++) {
        if (arr[j] & 1 << i) count++;
      }
      if (count % 3 != 0) result |= 1 << i;
    }
    return result;
  }
};

// Method 2:- Don't know
int singleElement(int arr[], int N) {
  int ones = 0, twos = 0;
  for (int i = 0; i < N; i++) {
    ones = (ones ^ arr[i]) & ~twos;
    twos = (twos ^ arr[i]) & ~ones;
  }
  return ones;
}

// Method 3:- Don't know
int singleElement(int arr[], int N) {
  int ones = 0, twos = 0;
  int common_bit_mask;
  for (int i = 0; i < N; i++) {
    twos = twos | (ones & arr[i]);
    ones = ones ^ arr[i];
    common_bit_mask = ~(ones & twos);
    ones &= common_bit_mask;
    twos &= common_bit_mask;
  }
  return ones;
}

// Method 4:- Brute force approach
//Time Complexity :- O(nlogn)
//Space Complexity :- O(1)
int singleElement(int arr[], int n) {
  sort(arr, arr + n);
  int i = 0;
  while (i < n - 1) {
    if (arr[i] == arr[i + 1]) i += 3;
    else return arr[i];
  }
  return arr[n - 1];
}

// Method 5:-
//Time Complexity :- O(n)
//Space Complexity :- O(n)
int singleElement(int arr[], int N) {
  set<int> st;
  int sum = 0, thrice_sum = 0;;
  for (int i = 0;i < N;i++) {
    st.insert(arr[i]);
    sum += arr[i];
  }
  for (auto it : st) thrice_sum += it;
  return (3 * thrice_sum - sum) / 2;
}

// Method :- 6

int singleElement(int arr[], int N) {
  unordered_map<int, int> mp;
  for (int i = 0; i < N; i++) mp[arr[i]]++;
  for (auto it : mp) {
    if (it.second == 1) return it.first;
  }
}
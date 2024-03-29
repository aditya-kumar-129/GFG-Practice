#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n) {
  unordered_set<int> s;
  for (int i = 0; i < size; i++) s.insert(arr[i]);
  for (int i = 0; i < size; i++) {
    if (s.find(arr[i] + n) != s.end()) return true;
  }
  return false;
}

// Method 2:-  It's space complexity will be O(1).

bool findPair(int arr[], int size, int n) {
  sort(arr, arr + size);
  int i = 0, j = 1;
  while (i < size && j < size) {
    if (arr[j] - arr[i] == n) return true;
    else if (arr[j] - arr[i] < n) j++;
    else i++;
  }
  return false;
}

/*Method 3 :-
Space Complexity:- O(1)
The below article will help in learning about INBUILT binary search Function
https://www.geeksforgeeks.org/binary-search-algorithms-the-c-standard-template-library-stl/ */

bool findPair(int arr[], int size, int n) {
  sort(arr, arr + size);
  for (int i = 0; i < size - 1; i++) {
    if (binary_search(arr, arr + size, (arr[i] + n))) return true;
  }
  return false;
}
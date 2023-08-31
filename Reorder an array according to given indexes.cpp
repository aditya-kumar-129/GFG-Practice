#include <iostream>
using namespace std;
// OPTIMUM SOLUTION
// Time complexity:- O(n)
// Space Complexity:- O(1)
void reorder(int arr[], int index[], int n) {
  for (int i = 0; i < n; i++) {
    while (index[i] != i) {
      swap(arr[i], arr[index[i]]);
      swap(index[i], index[index[i]]);
    }
  }
}

// BRUTE FORCE APPROACH
// Time complexity:- O(n)
// Space Complexity:- O(n)
void reorder(int arr[], int index[], int n) {
  int temp[n];
  for (int i = 0; i < n; i++) temp[index[i]] = arr[i];
  for (int i = 0; i < n; i++) {
    arr[i] = temp[i];
    index[i] = i;
  }
}
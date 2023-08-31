#include <bits/stdc++.h>
using namespace std;
// https://stackoverflow.com/questions/4773807/searching-in-a-sorted-and-rotated-array
// https://www.youtube.com/watch?v=Le8bc8aHgBA

class Solution {
public:
  int search(int A[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (A[mid] == key) return mid;
    //If left part is sorted
    if (A[low] <= A[mid]) {
      if (key >= A[low] && key <= A[mid])
        return search(A, low, mid - 1, key);
      return search(A, mid + 1, high, key);
    }
    //if right part is sorted
    else {
      if (key >= A[mid] && key <= A[high])
        return search(A, mid + 1, high, key);
      return search(A, low, mid - 1, key);
    }
  }
};

// Iterative appproach:-
int search(int A[], int low, int high, int key) {
  while (low <= high) {
    int mid = (low + high) / 2;
    if (A[mid] == key) return mid;
    if (A[low] < A[mid]) {
      if (A[low] <= key && A[mid] > key) high = mid - 1;
      else low = mid + 1;
    }
    else {
      if (A[mid] < key && A[high] >= key) low = mid + 1;
      else high = mid - 1;
    }
  }
  return -1;
}
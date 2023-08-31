#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void quickSort(int arr[], int low, int high) {
    if (low < high) {
      int pi = partition(arr, low, high);
      quickSort(arr, low, pi);
      quickSort(arr, pi + 1, high);
    }
  }

public:
  int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true) {
      //Find leftmost element greater than or equal to pivot
      do {
        i++;
      } while (arr[i] < pivot);
      //Find leftmost element greater than or equal to pivot
      do {
        j--;
      } while (arr[j] > pivot);
      // If two pointers met.
      if (i >= j) return j;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
};
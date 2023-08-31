#include <bits/stdc++.h>
using namespace std;

// OPTIMUM SOLUTION
// Time Complexity:- O(log(n))
// Have a look on the below Youtube video :- 
// https://www.youtube.com/watch?v=4WmTRFZilj8
class Solution {
public:
  int findKRotation(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if ((arr[mid] < arr[(mid + n - 1) % n]) && (arr[mid] < arr[(mid + 1) % n]))
        return mid;
      else if (arr[mid] < arr[high]) high = mid - 1;
      else low = mid + 1;
    }
    return low;
  }
};

// Method 2 :- 
// BRUTE FORCE APPROACH
// here min_element return a pointer to the index where the minimum elemen is present 
// and arr point to the start pointer and when the both are subtracted then we get the answer 
int findKRotation(int arr[], int n) {
  int c = min_element(arr, arr + n) - arr;
  return c;
}

// BRUTE FORCE APPROACH
// Time Complexity :- O(n)
int findKRotation(int arr[], int n) {
  int count = 0;
  int x = *min_element(arr, arr + n);
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > x) count++;
    else break;
  }
  return count;
}
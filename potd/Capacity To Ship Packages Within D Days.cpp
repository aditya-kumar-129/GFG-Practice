#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(int arr[], int min_curr, int noOfDays, int noOfPackages)
  {
    int noOfStudentAllocated = 1;
    int curr_sum = 0;
    for (int i = 0;i < noOfPackages;i++)
    {
      if (curr_sum + arr[i] > min_curr)
      {
        noOfStudentAllocated++;
        curr_sum = arr[i];
        if (noOfStudentAllocated > noOfDays)
          return false;
      }
      else
        curr_sum += arr[i];
    }
  }
  int leastWeightCapacity(int arr[], int noOfPackages, int noOfDays) {
    if (noOfPackages < noOfDays)
      return -1;
    int low = *max_element(arr, arr + noOfPackages);
    int high = accumulate(arr, arr + noOfPackages, high);
    int curr_min;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (isPossible(arr, mid, noOfDays, noOfPackages))
      {
        curr_min = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
    }
    return curr_min;
  }
};
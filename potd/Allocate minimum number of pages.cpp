#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPossible(int arr[], int min_curr, int noOfStudentsAvailable, int noOfBooksToBeAllocated)
  {
    int noOfStudentAllocated = 1;
    int curr_sum = 0;
    for (int i = 0;i < noOfBooksToBeAllocated;i++)
    {
      if (curr_sum + arr[i] > min_curr)
      {
        noOfStudentAllocated++;
        curr_sum = arr[i];
        if (noOfStudentAllocated > noOfStudentsAvailable)
          return false;
      }
      else
        curr_sum += arr[i];
    }
  }
  int findPages(int arr[], int noOfBooksToBeAllocated, int noOfStudentsAvailable)
  {
    if (noOfBooksToBeAllocated < noOfStudentsAvailable)
      return -1;
    int low = *max_element(arr, arr + noOfBooksToBeAllocated);
    int high = accumulate(arr, arr + noOfBooksToBeAllocated, high);
    int curr_min;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (isPossible(arr, mid, noOfStudentsAvailable, noOfBooksToBeAllocated))
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

// Similar questions :- 
// 1482 Minimum Number of Days to Make m Bouquets(Leetcode)
// 1231 Divide Chocolate(Leetcode)
// 1011 Capacity To Ship Packages In N Days(Leetcode)
// 774 Max Distance to Gas Station(Leetcode)
// 410 Split Array Largest Sum(Leetcode)
// Aggressive cow(spoj)
// Prata and roti(spoj)
// EKO(spoj)
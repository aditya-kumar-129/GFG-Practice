#include <bits/stdc++.h>
using namespace std;
// Have a look on the youtube video :- https://youtu.be/WFNa5o-dHGo
// Required Time Complexity:- O(logn)
// Required Space Complexity:- O(1)

class Solution
{
public:
  // Time Complexity:- O(logn)
  // Space Complexity:- O(1)
  int findOnce(int arr[], int n)
  {
    int start = 0;
    int end = n - 1;
    // When there is only one element present in the array
    if (n == 1)
      return arr[0];
    // When the first element of the array is the answer
    if (arr[0] != arr[1])
      return arr[0];
    // When the last element of the array is the answer
    if (arr[n - 2] != arr[n - 1])
      return arr[n - 1];

    while (start <= end)
    {
      int mid = (start + end) / 2;
      if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        return arr[mid];
      else if (arr[mid] == arr[mid - 1])
      {
        // Left count denotes the number of element that lie between the start and mid including the element present at start and mid positions.
        int left_count = mid - start + 1;
        if (left_count % 2 == 0)
          start = mid + 1;
        else
          end = mid - 2;
      }
      else if (arr[mid] == arr[mid + 1])
      {
        // Right count denotes the number of element that lie between the mid and high including the element present at mid and high positions.
        int right_count = end - mid + 1;
        if (right_count % 2 == 0)
          end = mid - 1;
        else
          start = mid + 2;
      }
    }
  }
};

// OPTIMISED SOLUTION
// 1) Find the middle index, say ‘mid’.
// 2) If ‘mid’ is even, then compare arr[mid] and arr[mid +1]. If both are the same, then the required element after ‘mid’ and else before mid.
// 3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are the same, then the required element after‘mid’ and else before mid.
int findOnce(int arr[], int n)
{
  int lo = 0, hi = n - 1;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
      return arr[mid];
    else if ((arr[mid] == arr[mid - 1] && mid % 2 != 0) || (arr[mid] == arr[mid + 1] && mid % 2 == 0))
      lo = mid + 1;
    else
      hi = mid - 1;
  }
}

// Method:-  Don't know
int search(int A[], int N) {
  //code
  int low = 0, high = N - 1;
  while (low <= high) 
  {
    int mid = (low + high) >> 1;
    if (A[mid] == A[mid ^ 1])
      low = mid + 1;
    else high = mid - 1;
  }
  return A[low];
}

// Method:- 2
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int findOnce(int arr[], int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
    res ^= arr[i];
  return res;
}

// Method:- 3
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int findOnce(int arr[], int n)
{
  for (int i = 1; i < n - 1; i++)
    if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
      return arr[i];
  //Checking boundary cases
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];
}

// I don't think that it solves under the time complexity of O(logn) 
int findOnce(int arr[], int n)
{
  int i = 0, j = n - 1;
  while (i <= j)
  {
    if (arr[i] != arr[i + 1])
      return arr[i];
    else if (arr[j] != arr[j - 1])
      return arr[j];
    i += 2;
    j -= 2;
  }
  return -1;
}
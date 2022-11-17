// See the youtube video for explanation of 1st method:- https://youtu.be/5L9Jrehvoew
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getPairsCount(int arr[], int n, int k)
  {
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (m.find(k - arr[i]) != m.end())
        count += m[k - arr[i]]; // Since we have to consider solution which includes DUPLICATE ELEMENT ALSO
      m[arr[i]]++;
    }
    return count;
  }
};

// Using two pointer Algorithm
int getPairsCount(int arr[], int n, int k) {
  sort(arr, arr + n);
  int end = n - 1;
  int start = 0;
  int ans = 0;
  while (start < end) 
  {
    if (arr[start] + arr[end] == k) 
    {
      ans++;
      int i = start + 1;
      //this loop to  include the case when their are identical numbers whose sum equal to k
      while (i < end && arr[i] + arr[end] == k) 
      {
        ans++;
        i++;
      }
      end--;
    }
    else if (arr[start] + arr[end] > k) 
      end--;
    else 
      start++;
  }
  return ans;
}
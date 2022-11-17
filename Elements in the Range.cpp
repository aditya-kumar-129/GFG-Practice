#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
// Time Complexity :- O(nlogn)
  bool check_elements(int arr[], int n, int A, int B)
  {
    sort(arr, arr + n);
    for (int i = A; i <= B; i++)
      if (!binary_search(arr, arr + n, i))
        return false;
    return true;
  }
};

// Method 2:-
// Space Complexity :- O(n)
// Time Complexity :- O(n)
bool check_elements(int arr[], int n, int A, int B)
{
  map<int, int> mp;
  for (int i = 0; i < n; i++)
    if (arr[i] >= A && arr[i] <= B)
      mp[arr[i]]++;
  int count = mp.size();
  if (count == (B - A + 1))
    return true;
  return false;
}

// method 3 :- 
bool check_elements(int arr[], int n, int A, int B)
{
  sort(arr, arr + n);
  int k = 0;
  for (int i = 0;i < n;i++)
    if (arr[i] == A + k && arr[i] <= B)
      k++;
  if (k - 1 == B - A)
    return true;
  else
    return false;
}
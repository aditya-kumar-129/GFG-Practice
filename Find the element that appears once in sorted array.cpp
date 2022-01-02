#include <bits/stdc++.h>
using namespace std;
// Have a look on the below youtube video :-
// https://youtu.be/WFNa5o-dHGo

class Solution
{
public:
  int findOnce(int arr[], int n)
  {
    int start = 0;
    int end = n - 1;
    if (n == 1)
      return arr[0];
    if (arr[0] != arr[1])
      return arr[0];
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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
      cin >> A[i];
    Solution ob;
    int res = ob.findOnce(A, n);
    cout << res << endl;
  }
  return 0;
}

// Time Complexity:- O(n)
int findOnce(int arr[], int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
    res = res ^ arr[i];
  return res;
}

// Method 2:- Time Complexity:- O(log(n))  DONT GET THIS METHOD
int findOnce(int arr[], int n)
{
  if (n == 1)
    return arr[0];
  int k = 1;
  for (int i = 0; i < n; i = 2 * k++)
    if (i == (n - 1) || (arr[i] != arr[i + 1]))
      return arr[i];
  return -1;
}

// Method:-3
int findOnce(int arr[], int n)
{
  for (int i = 1; i < n - 1; i++)
    if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
      return arr[i];

  if (arr[0] != arr[1])
    return arr[0];

  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];
}

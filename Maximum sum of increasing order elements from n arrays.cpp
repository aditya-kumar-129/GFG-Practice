#include<bits/stdc++.h>
using namespace std;

int maximumSum(int n, int m, vector<vector<int>>& a)
{
  int temp = INT_MAX;
  int arr[n];
  for (int i = n - 1;i >= 0;i--)
  {
    int max = 0;
    for (int j = 0;j < m;j++)
      if (a[i][j] > max && a[i][j] < temp)
        max = a[i][j];
    temp = max;
    arr[i] = max;

  }
  if (arr[0] == 0)
    return 0;
  int s = 0;
  return accumulate(arr, arr + n, s);
}
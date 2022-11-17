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

int main() 
{
  int t, n, m;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0;i < n;i++)
      for (int j = 0;j < m;j++)
        cin >> arr[i][j];
    cout << maximumSum(n, m, arr) << endl;
  }
  return 0;
}
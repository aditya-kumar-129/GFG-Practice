/*
For explanation of the logic see the below video:-
https://youtu.be/qUDp8IUbZto
https://youtu.be/ZHQg07n_tbg
*/
#include <iostream>
using namespace std;

long long maxArea(long long A[], int len)
{
  long long int l = 0;
  long long int r = len - 1;
  long long int area = 0;
  while (l < r)
  {
    area = max(area, min(A[l], A[r]) * (r - l));
    if (A[l] < A[r])
      l++;
    else
      r--;
  }
  return area;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    cout << maxArea(arr, n) << endl;
  }
  return 0;
}
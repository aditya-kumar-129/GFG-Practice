#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int search(int a[], int n)
  {
    int sum = a[0];
    for (int i = 1; i < n; i++)
      sum = sum ^ a[i];
    return sum;
  }
};

int main()
{
  int t, len;
  cin >> t;
  while (t--)
  {
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.search(arr, len) << '\n';
  }
  return 0;
}
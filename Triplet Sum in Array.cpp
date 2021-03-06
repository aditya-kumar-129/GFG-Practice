#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Two Pointer Algorithm Approach
  bool find3Numbers(int a[], int n, int x)
  {
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
      if (twoSum(a, x - a[i], i + 1, n))
        return true;
    return false;
  }

  bool twoSum(int a[], int sum, int i, int n)
  {
    int j = n - 1;
    while (i < j)
    {
      if (a[i] + a[j] > sum)
        j--;
      else if (a[i] + a[j] < sum)
        i++;
      else
        return true;
    }
    return false;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, X;
    cin >> n >> X;
    int i, A[n];
    for (i = 0; i < n; i++)
      cin >> A[i];
    Solution ob;
    cout << ob.find3Numbers(A, n, X) << endl;
  }
}
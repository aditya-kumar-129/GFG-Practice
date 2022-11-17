#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxVal(int a[], int n)
  {
    for (int i = 0; i < n; i++)
      a[i] = a[i] - i;
    sort(a, a + n);
    return a[n - 1] - a[0];
  }
};
#include <bits/stdc++.h>
using namespace std;

long long MaxSum(long long int a[], long long int b[], long long int n)
{
  sort(a, a + n);
  sort(b, b + n);
  long long int s = 0;
  for (int i = 0; i < n; i++)
    s += (a[i] * b[i]);
  return s;
}
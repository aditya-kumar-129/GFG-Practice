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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long int n;
    cin >> n;
    long long int a[n], b[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    cout << MaxSum(a, b, n) << endl;
  }
  return 0;
}
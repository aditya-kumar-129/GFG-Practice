#include <bits/stdc++.h>
using namespace std;

long long leftCandies(long long n, long long m)
{
  if (n == 1)
    return 0;
  long long int total_candy_in_single_rotation = n * (n + 1) / 2;
  m = m % total_candy_in_single_rotation;
  for (long long int i = 1; m > 0; i++)
  {
    if (m < i)
      break;
    m -= i;
  }
  return m;
}
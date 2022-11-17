#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution
{
public:
  int countBits(int N, long long int A[])
  {
    long long ans = 0, ones, zeroes;
    long mod = 1000000007;
    for (int i = 0; i < 32; i++)
    {
      ones = 0, zeroes = 0;
      for (long long j = 0; j < N; j++)
      {
        if (A[j] & (1 << i))
          ones++;
        else
          zeroes++;
      }
      ans = ((ans % mod) + (ones * zeroes * 2) % mod) % mod;
    }
    return ans;
  }
};

// Method 2:-

int countBits(int N, long long int arr[])
{
  static int mod = 1000000007;
  int bitPos = 0;
  long long int ans = 0;
  while (bitPos < 32)
  {
    long long int num0 = 0, num1 = 0;
    for (long long int i = 0; i < N; i++)
    {
      num1 += (arr[i] & 1);
      arr[i] >>= 1;
    }
    num0 = (N - num1) % mod;
    ans += (2 * (num0 * num1)) % mod;
    bitPos++;
  }
  return ans % mod;
}

// Method 3:-
int countBits(int N, long long int A[])
{
  long mod = 1000000007;
  long long int count = 0;
  for (int i = 0; i < 32; i++)
  {
    long long int one = 0;
    for (int j = 0; j < N; j++)
      one += ((A[j] >> i) & 1);
    count += (2 * (one % mod) * ((N - one) % mod)) % mod;
  }
  return (count) % mod;
}
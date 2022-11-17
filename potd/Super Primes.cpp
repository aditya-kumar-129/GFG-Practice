#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void SieveOfEratosthenes(int n, bool isPrime[])
  {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
      isPrime[i] = true;

    for (int p = 2; p * p <= n; p++)
      if (isPrime[p] == true)
        for (int i = p * 2; i <= n; i += p)
          isPrime[i] = false;
  }
  int superPrimes(int n)
  {
    bool isPrime[n + 1];
    SieveOfEratosthenes(n, isPrime);
    vector<int> v;
    for (int i = 0;i <= n;i++)
      if (isPrime[i])
        v.push_back(i);
    int count = 0;
    // 0,1 -->nom-prime
    // 2,3 --> prime but they can not be formed using two different prime numbers
    // 4 is also not prime that why we will start from the 5
    for (int i = 5;i <= n;i++)
      if (isPrime[i] && isPrime[i - 2])
        count++;
    return count;
  }
};
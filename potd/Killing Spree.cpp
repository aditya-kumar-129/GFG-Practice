#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long int killinSpree(long long int n)
  {
    long long int i = 1;
    long long int count = 0;
    while (n > 0)
    {
      n -= (i * i);
      count++;
      if (n < 0)
        count--;
      i++;
    }
    return count;
  }
};
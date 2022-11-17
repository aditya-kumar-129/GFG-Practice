/*
below is the youtube video to understand the below problem :-
https://youtu.be/mPPNFyBNyJY
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int makeProductOne(int a[], int n)
  {
    int positive = 0, negative = 0, zero = 0, step = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == 0)
        zero++;
      else if (a[i] < 0)
      {
        negative++;
        step = step + (-1 - a[i]);    // counting the number of steps required to make the negative number to -1
      }
      else
      {
        positive++;
        step = step + (a[i] - 1);  // counting the number of steps required to make the positive number to 1
      }
    }
    step += zero;
    if (negative % 2 == 1 && zero == 0)
      step += 2;
    return step;
  }
};
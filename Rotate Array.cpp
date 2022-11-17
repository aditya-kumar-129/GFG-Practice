/*
Refer the below youtube video to understand the A Juggling Algorithm (through which we can rotate the array satisfying the requirement of inplace)
https://youtu.be/utE_1ppU5DY
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int gcd(int a, int b)
  {
    if (b == 0)
      return a;
    else
      return gcd(b, a % b);
  }
  
  void rotateArr(int A[], int k, int n)
  {
    int d = -1, i, temp, j;
    k = k % n;  // To handle if k >= n
    for (i = 0; i < gcd(n, k); i++)
    {
      j = i;
      temp = A[i];
      while (1)
      {
        d = (j + k) % n;
        if (d == i)
          break;
        A[j] = A[d];
        j = d;
      }
      A[j] = temp;
    }
  }
};
/*
Few links that has been used here to solve this problem is :-
1.) https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
2.) https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countBitsFlip(int a, int b)
  {
    int temp = a ^ b;
    return __builtin_popcount(temp);
  }
};
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    Solution ob;
    cout << ob.countBitsFlip(a, b) << endl;
  }
  return 0;
}

// Method 2:-
int countBitsFlip(int a, int b)
{
  int x = a ^ b;
  bitset<32> bt(x);
  return bt.count();
}

// Method:-  3
int countBitsFlip(int a, int b)
{
  int n = a ^ b;
  int count = 0;
  while (n > 0)
  {
    n = (n & (n - 1));
    count++;
  }
  return count;
}

// Method 4:-
// refer the below YouTube Video for more understanding:-
// https://youtu.be/PvM39qzSh3E
int ans(int n)
{
  int c = 0;
  while (n > 0)
  {
    if (n & 1)
      c++;
    n = n >> 1;
  }
  return c;
}
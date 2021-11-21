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
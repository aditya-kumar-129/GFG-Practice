/*
Few links to get the number of 1 present in the binary representation of a decimal number is :-
1.) https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/
2.) There is one algorithm also :- https://www.geeksforgeeks.org/count-set-bits-in-an-integer/  Good Article
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Below method uses Brian Kernighan’s Algorithm 
  // Have a look on the the second article link of gfg that has been shared above
  // Have a look at the working of the Brian Kernighan’s Algorithm using the foolowing YouTube Video:- 
  // https://www.youtube.com/watch?v=e0sVe4-JJJI
  int setBits(int n)
  {
    if (n == 0)
      return 0;
    else
      return 1 + setBits(n & (n - 1));
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    Solution ob;
    int cnt = ob.setBits(N);
    cout << cnt << endl;
  }
  return 0;
}

// Method 1 :- time complexity :- O(logn)

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    // the result of logical and operation on any number with 1 results to
    // 1 if it's left most bit of the number is 1 and to
    // 0 if the left most bit of the number is 0
    count = count + (n & 1);
    // >> is the signed right shift operator so as to traverse all the binary digits of the number
    n = n >> 1; 
  }
  return count;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSquare(int b)
  {
    if (b & 1)
    {
      b--;
      return ((b * b) - (2 * b)) / 8;
    }
    else
      return ((b * b) - (2 * b)) / 8;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int B, count;
    cin >> B;
    Solution ob;
    count = ob.countSquare(B);
    cout << count << endl;
  }
}
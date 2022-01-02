#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isLucky(int n)
  {
    int deleteevery = 2;
    while (n >= deleteevery)
    {
      if (n % deleteevery == 0)
        return false;
      n -= (n / deleteevery);
      deleteevery++;
    }
    return true;
  }
};

signed main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    Solution obj;

    if (obj.isLucky(n))
      cout << "1\n";
    else
      cout << "0\n";
  }
}
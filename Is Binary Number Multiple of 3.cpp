#include <bits/stdc++.h>
using namespace std;

// See the below youtube video for more reference:-
// https://www.youtube.com/watch?v=Sd2ZjG20iUA

class Solution
{
public:
  int isDivisible(string s)
  {
    int evenPosCount = 0, oddPosCount = 0;
    for (long long int i = s.size() - 1; i >= 0; i--)
    {
      if (s[i] == '1' && i % 2 == 0)
        evenPosCount++;
      if (s[i] == '1' && i % 2 != 0)
        oddPosCount++;
    }
    if (abs(evenPosCount - oddPosCount) % 3 == 0)
      return 1;
    return 0;
  }
};

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.isDivisible(s) << endl;
  }
  return 0;
}

// Method 2:- So we know that 1 in a bianry number represent 2 power that index 
// We are using the same concept here and each time we are just finding the mod operaton as the input number can be very large and hence we can't store the final number if don't use the mod operation at each step.
int isDivisible(string s)
{
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    ans = (2 * ans + s[i] - '0') % 3;
  return ans == 0;
}
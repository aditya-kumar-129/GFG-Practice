#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findIndex(string str)
  {
    int len = str.length();
    int open[len + 1], close[len + 1];
    int index = -1;
    memset(open, 0, sizeof(open));
    memset(close, 0, sizeof(close));

    open[0] = 0;
    close[len] = 0;
    if (str[0] == '(')
      open[1] = 1;
    if (str[len - 1] == ')')
      close[len - 1] = 1;
    for (int i = 1; i < len; i++)
    {
      if (str[i] == '(')
        open[i + 1] = open[i] + 1;
      else
        open[i + 1] = open[i];
    }
    for (int i = len - 2; i >= 0; i--)
    {
      if (str[i] == ')')
        close[i] = close[i + 1] + 1;
      else
        close[i] = close[i + 1];
    }

    if (open[len] == 0)
      return len;
    if (close[0] == 0)
      return 0;

    for (int i = 0; i <= len; i++)
      if (open[i] == close[i])
        index = i;

    return index;
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
    cout << ob.findIndex(s) << endl;
  }
}
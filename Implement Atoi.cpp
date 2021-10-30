#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int atoi(string str)
  {
    int res = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-')
    {
      sign = -1;
      i++;
    }
    for (; str[i] != '\0'; ++i)
    {
      int char_value = int(str[i]);
      if ((char_value >= 97 && char_value <= 122) || (char_value >= 65 && char_value <= 90))
        return -1;
      else
        res = res * 10 + str[i] - '0';
    }
    return sign * res;
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
    cout << ob.atoi(s) << endl;
  }
}
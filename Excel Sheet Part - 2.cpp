#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int ExcelColumnNumber(string s)
  {
    int result = 0;
    for (auto c : s)
    {
      result *= 26;
      result += c - 'A' + 1;
    }
    return result;
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
    cout << ob.ExcelColumnNumber(s) << endl;
  }
}
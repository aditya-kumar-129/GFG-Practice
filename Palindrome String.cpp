#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPalindrome(string str)
  {
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
      if (str[l++] != str[h--])
        return 0;
    return 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.isPalindrome(s) << "\n";
  }
  return 0;
}
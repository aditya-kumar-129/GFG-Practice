#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  char nonrepeatingCharacter(string s)
  {
    map<char, int> m;
    char ch;
    for (int i = 0; i < s.length(); i++)
      m[s[i]]++;
    for (int i = 0; i < s.length(); i++)
    {
      if (m.find(s[i]) != m.end())
      {
        auto it = m.find(s[i]);
        if (it->second == 1)
        {
          return it->first;
          break;
        }
      }
    }
    return '$';
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string S;
    cin >> S;
    Solution obj;
    char ans = obj.nonrepeatingCharacter(S);
    if (ans != '$')
      cout << ans;
    else
      cout << "-1";
    cout << endl;
  }
  return 0;
}
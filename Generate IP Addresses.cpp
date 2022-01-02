#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void recfunc(string s, int st, int e, int d, string str, vector<string> &ans)
  {
    if (d == 3 || st >= e)
    {
      string temp = "";
      if (d == 3 && e - st + 1 <= 3 && e - st + 1 > 0)
      {
        for (int i = st; i <= e; i++)
          temp += s[i];
        if (stoi(temp) >= 256 || (temp.size() > 1 && temp[0] == '0'))
          return;
        ans.push_back(str + temp);
      }
      return;
    }
    string temp = "";

    for (int i = st, j = 0; j < 3 && i <= e; i++, j++)
    {
      temp += s[i];
      if (stoi(temp) >= 256 || (temp.size() > 1 && temp[0] == '0'))
        return;
      recfunc(s, i + 1, e, d + 1, str + temp + ".", ans);
    }
  }

  vector<string> genIp(string &s)
  {
    vector<string> ans;
    recfunc(s, 0, s.size() - 1, 0, "", ans);
    return ans;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string s;
    cin >> s;
    Solution obj;
    vector<string> str = obj.genIp(s);
    sort(str.begin(), str.end());
    for (auto &u : str)
      cout << u << "\n";
  }
}
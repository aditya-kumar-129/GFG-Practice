#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findRange(string s, int n)
  {
    vector<int> ans;
    int count_one = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == '1')
        count_one++;
    if (count_one == n)
    {
      ans.push_back(-1);
      return ans;
    }
    int start = 0, end = 0, cur = 0, prev = 0, count = -1;
    for (int i = 0; i < n; i++)
    {
      cur += (s[i] == '0') ? 1 : -1;
      if (count < cur)
      {
        count = cur;
        start = prev;
        end = i;
      }
      if (cur < 0)
      {
        cur = 0;
        prev = i + 1;
      }
    }
    ans.push_back(start + 1);
    ans.push_back(end + 1);
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.findRange(s, n);
    if (ans.size() == 1)
      cout << ans[0] << "\n";
    else
      cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
}
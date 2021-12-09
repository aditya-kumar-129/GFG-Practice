#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string FirstNonRepeating(string a)
  {
    int arr[26] = {0};
    queue<int> q;
    for (int i = 0; i < a.length(); i++)
    {
      arr[a[i] - 'a']++;
      if (arr[a[i] - 'a'] == 1)
        q.push(a[i]);
      while (!q.empty() && arr[q.front() - 'a'] != 1)
        q.pop();
      if (q.empty())
        a[i] = '#';
      else
        a[i] = q.front();
    }
    return a;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    string A;
    cin >> A;
    Solution obj;
    string ans = obj.FirstNonRepeating(A);
    cout << ans << "\n";
  }
  return 0;
}
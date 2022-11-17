#include <bits/stdc++.h>
#define N 10000
using namespace std;

class Solution {
public:
  vector<int> print_next_greater_freq(int arr[], int n)
  {
    vector<int> res(n, 0);
    map<int, int> mp;
    for (int i = 0;i < n;i++)
      mp[arr[i]]++;
    stack<int> s;
    s.push(0);
    for (int i = 1;i < n;i++)
    {
      if (mp[arr[i]] < mp[arr[s.top()]])
        s.push(i);
      else
      {
        while (!s.empty() && mp[arr[i]] > mp[arr[s.top()]])
        {
          res[s.top()] = arr[i];
          s.pop();
        }
        s.push(i);
      }
    }
    while (!s.empty())
    {
      res[s.top()] = -1;
      s.pop();
    }
    return res;
  }
};

int main()
{
  int arr[N];
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> ans = ob.print_next_greater_freq(arr, n);
    for (auto x : ans)
      cout << x << " ";
    cout << endl;
  }
  return 1;
}
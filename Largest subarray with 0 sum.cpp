/*
Below is video link for the explanation of the problem:-
https://www.youtube.com/watch?v=xmguZ6GbatA
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxLen(vector<int> &A, int n)
  {
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      sum += A[i];
      if (sum == 0)
        maxLen = i + 1;
      else
      {
        if (m.find(sum) != m.end())
          maxLen = max(maxLen, i - m[sum]);
        else
          m[sum] = i;
      }
    }
    return maxLen;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int m;
    cin >> m;
    vector<int> array1(m);
    for (int i = 0; i < m; ++i)
      cin >> array1[i];
    Solution ob;
    cout << ob.maxLen(array1, m) << endl;
  }
  return 0;
}
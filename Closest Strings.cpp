#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestDistance(vector<string> &s, string word1, string word2)
  {
    int index1 = -1, index2 = -1;
    int min_dist = INT_MAX;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == word1)
        index1 = i;
      if (s[i] == word2)
        index2 = i;
      int temp = abs(index1 - index2);
      if (index1 != -1 && index2 != -1)
        min_dist = min(min_dist, temp);
    }
    return min_dist;
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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];
    string word1, word2;
    cin >> word1 >> word2;
    Solution ob;
    cout << ob.shortestDistance(s, word1, word2) << "\n";
  }
  return 0;
}
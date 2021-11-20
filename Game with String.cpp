// https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minValue(string s, int k)
  {
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
      mp[s[i]]++;
    priority_queue<int> pq;
    for (auto i : mp)
      pq.push(i.second);
    while (k--)
    {
      int x = pq.top();
      pq.pop();
      x--;
      pq.push(x);
    }
    int sum = 0;
    while (!pq.empty())
    {
      sum += pow(pq.top(), 2);
      pq.pop();
    }
    return sum;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    int k;
    cin >> s >> k;
    Solution ob;
    cout << ob.minValue(s, k) << "\n";
  }
  return 0;
}
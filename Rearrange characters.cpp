#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string rearrangeString(string str)
  {
    // In order to get which character has occured how many times we have to use map and in map sorting takes place on the basis of characters and not on the basis of their frequency 
    //unordered map has been used here because it takes O(1) time to get the frequency array where as map takes O(logn) time
    unordered_map<char, int> mp;
    int n = str.size();
    for (int i = 0; i < n; i++)
      mp[str[i]]++;
    // and now we have to use priority queue to store the frequency in descending order and this is the reason parameters being passed to to the map and priority queue are different 
    priority_queue<pair<int, char>> pq;
    for (auto x : mp)
      pq.push({x.second, x.first});
    string c = "";
    while (pq.size() > 1)
    {
      pair<int, char> p1 = pq.top();
      pq.pop();
      pair<int, char> p2 = pq.top();
      pq.pop();
      c += p1.second;
      c += p2.second;
      if (p1.first > 1)
        pq.push({p1.first - 1, p1.second});
      if (p2.first > 1)
        pq.push({p2.first - 1, p2.second});
    }
    if (pq.size() > 0 && pq.top().first > 1)
      return "-1";
    if (pq.size() > 0)
      c += pq.top().second;
    return c;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    Solution ob;
    string str1 = ob.rearrangeString(str);
    int flag = 1;
    int c[26] = {0};
    for (int i = 0; i < str.length(); i++)
      c[str[i] - 'a'] += 1;
    int f = 0;
    int x = (str.length() + 1) / 2;
    for (int i = 0; i < 26; i++)
      if (c[i] > x)
        f = 1;
    if (f)
    {
      if (str1 == "-1")
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
    else
    {
      int a[26] = {0};
      int b[26] = {0};
      for (int i = 0; i < str.length(); i++)
        a[str[i] - 'a'] += 1;
      for (int i = 0; i < str1.length(); i++)
        b[str1[i] - 'a'] += 1;
      for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
          flag = 0;
      for (int i = 0; i < str1.length(); i++)
        if (i > 0)
          if (str1[i - 1] == str1[i])
            flag = 0;
      if (flag == 1)
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
  return 0;
}
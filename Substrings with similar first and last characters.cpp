#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubstringWithEqualEnds(string s)
  {
    int result = 0;
    int n = s.length();
    int count[26] = { 0 };
    for (int i = 0; i < n; i++)
      count[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
      result += (count[i] * (count[i] + 1) / 2);
    return result;
  }
};

// Method 2:-  Using map

int countSubstringWithEqualEnds(string s)
{
  int count = 0;
  map<char, int> m;
  for (int i = 0; i < s.size(); i++)
    m[s[i]]++;
  for (auto i : m)
    if (i.second > 1)
      count += (i.second) * (i.second - 1) / 2;
  return count;
}
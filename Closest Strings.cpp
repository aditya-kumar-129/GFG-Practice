#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestDistance(vector<string>& s, string word1, string word2)
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
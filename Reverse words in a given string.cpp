#include <bits/stdc++.h>
using namespace std;
// Only method how to store different words present between the dots are important

class Solution
{
public:
  void methodToStoreDifferentWords(string s, string del = " ")
  {
    int start = 0;
    int end = s.find(del);
    vector<string> v;
    while (end != -1)
    {
      v.push_back(s.substr(start, end - start));
      start = end + del.size();
      end = s.find(del, start);
    }
    v.push_back(s.substr(start, end - start));
    vector<string> v1;
    for (int j = v.size() - 1; j >= 0; j--)
    {
      v1.push_back(v[j]);
      if (j == 0)
        break;
      v1.push_back(".");
    }
    for (int i = 0; i < v1.size(); i++)
      cout << v1[i];
  }
  string reverseWords(string S)
  {
    methodToStoreDifferentWords(S, ".");
  }
};
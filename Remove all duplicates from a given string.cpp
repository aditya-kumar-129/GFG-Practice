#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeDuplicates(string str)
  {
    string ans = "";
    unordered_set<char> st;
    for (int i = 0; i < str.length(); i++)
    {
      if (st.find(str[i]) == st.end())
      {
        st.insert(str[i]);
        ans += str[i];
      }
    }
    return ans;
  }
};
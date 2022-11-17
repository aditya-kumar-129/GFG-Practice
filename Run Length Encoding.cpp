#include <bits/stdc++.h>
using namespace std;

string encode(string s)
{
  // string s;
  // map<char, int> m;
  // map<char, bool> check;
  // for (int i = 0; i < src.length(); i++)
  // {
  //   m[src[i]]++;
  //   check[src[i]] = false;
  // }
  // for (int i = 0; i < src.length(); i++)
  // {
  //   if (check[src[i]] == false)
  //   {
  //     auto it = m.find(src[i]);
  //     s = s + it->first;
  //     s = s + to_string(it->second);
  //     check[src[i]] = true;
  //   }
  // }
  // return s;
  /*
  Above method does not work in case of the following testcase:-
  hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac
  whose output should be like this:-
  h1n1w1n1k1u1e1w1h1s1q1m1g1b2u1q1c1l1j2i1v1s1w1m1d1k1q1t1b1x1i1x1m1v1t1r2b1l1j1p1t1n1s1n1f1w1z1q1f1j1m1a1f1a1d1r2w1s1o1f1s1b1c1n1u1v1q1h1f2b1s1a1q1x1w1p1q1c1a1c1
  but i got the beow output using map:-
  h3n5w6k2u3e1s6q7m4g1b6c4l2j4i2v3d2t3x3r4p2f6z1a4o1
  */

  int c = 1;
  for (int i=0;i<s.length();i++)
  {
    if (s[i]==s[i+1])
      c++;
    else
    {
      cout<<s[i]<<c;
      c=1;
    }
  }
}
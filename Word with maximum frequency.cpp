/*
topics need to cover in order to solve this problem is (if you want to use inbuilt function):-
https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
*/

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string maximumFrequency(string s)
{
  vector<string> v;
  istringstream ss(s);
  string word;
  while (ss >> word)
    v.push_back(word);
  map<string, int> m;
  for (int i = 0; i < v.size(); i++)
    m[v[i]]++;
  int max_freq = 0;
  for (auto it : m)
    if (it.second > max_freq)
      max_freq = it.second;
  string ans;
  if (max_freq == 1)
    ans = v[0] + " 1";
  else
  {
    for (int i = 0; i < v.size(); i++)
    {
      auto it = m.find(v[i]);
      if (it->second == max_freq)
      {
        ans = it->first + " " + to_string(it->second);
        break;
      }
    }
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  for (int i = 0; i < t; i++)
  {
    string s;
    getline(cin, s);
    cout << maximumFrequency(s) << endl;
  }
  return 0;
}


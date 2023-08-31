/*
topics need to cover in order to solve this problem is (if you want to use inbuilt function):-
https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
*/

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string maximumFrequency(string s) {
  vector<string> v;
  istringstream ss(s);
  string word;
  while (ss >> word) v.push_back(word);
  map<string, int> mp;
  for (int i = 0; i < v.size(); i++) mp[v[i]]++;
  int max_freq = 0;
  for (auto it : mp) {
    if (it.second > max_freq) max_freq = it.second;
  }
  string ans;
  if (max_freq == 1) ans = v[0] + " 1";
  else {
    for (int i = 0; i < v.size(); i++) {
      auto it = mp.find(v[i]);
      if (it->second == max_freq) {
        ans = it->first + " " + to_string(it->second);
        break;
      }
    }
  }
  return ans;
}
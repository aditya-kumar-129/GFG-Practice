#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // OPTIMISED SOLUTION
  // In this case we don't have to traverse the same string twice.
  char nonrepeatingCharacter(string S) {
    int count_map[256] = { -1 };
    for (int i = 0; i < S.length(); i++) {
      if (count_map[S[i]] == -1) {
        count_map[S[i]] = i;
        continue;
      }
      count_map[S[i]] = -2;
    }
    int res = INT_MAX;
    for (int i = 0; i < 256; i++) {
      if (count_map[i] >= 0) res = min(res, count_map[i]);
    }

    if (res == INT_MAX) return '$';
    return S[res];
  }
};

// OPTIMSED SOLUTION
// In this case we don't have to traverse the same string twice.
char nonrepeatingCharacter(string S) {
  int result = INT_MAX;
  pair<int, int> helper[256];
  for (int i = 0;i < S.size();i++) {
    (helper[S[i]].first)++;
    helper[S[i]].second = i;
  }
  for (int i = 0;i < 256;i++) {
    if (helper[i].first == 1) {
      result = min(result, helper[i].second);
    }
  }
  if (result == INT_MAX) return '$';
  return S[result];
}

// Bryte force approach 
// In this method we have to traverse the same string twice
char nonrepeatingCharacter(string s) {
  map<char, int> m;
  char ch;
  for (int i = 0; i < s.length(); i++) m[s[i]]++;
  for (int i = 0; i < s.length(); i++) {
    if (m[s[i]] == 1) return s[i];
  }
  return '$';
}

// Brute force approach
char nonrepeatingCharacter(string s) {
  //https://stackoverflow.com/questions/9438209/for-every-character-in-string
  unordered_map<char, int> mp;
  for (char& i : s)
    mp[i]++;
  for (char& i : s) {
    if (mp[i] == 1) return i;
  }
  return '$';
}
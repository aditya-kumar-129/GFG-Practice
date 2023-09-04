// Question Link :- https://practice.geeksforgeeks.org/problems/alternate-vowel-and-consonant-string2939/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }
  string rearrange(string str, int N) {
    map<char, int> mpVowels, mpConsonants;
    vector<char> vowels, consonants;
    for (auto it : str) {
      if (it != ' ' && checkVowel(it)) mpVowels[it]++;
      else if (it != ' ' && !checkVowel(it)) mpConsonants[it]++;
    }
    for (auto& it : mpVowels) {
      int frequency = it.second;
      while (frequency--) vowels.push_back(it.first);
    }

    for (auto& it : mpConsonants) {
      int frequency = it.second;
      while (frequency--) consonants.push_back(it.first);
    }

    int vowelSize = vowels.size(), consonantsSize = consonants.size();
    if (abs(vowelSize - consonantsSize) > 1) return "-1";
    string ans = "";
    int i = 0, j = 0;
    while (i < vowels.size() && j < consonants.size()) {
      if (vowelSize > consonantsSize) {
        ans += vowels[i++];
        ans += consonants[j++];
      }
      else if (vowelSize == consonantsSize) {
        if (vowels[0] > consonants[0]) {
          ans += consonants[j++];
          ans += vowels[i++];
        }
        else {
          ans += vowels[i++];
          ans += consonants[j++];
        }
      }
      else {
        ans += consonants[j++];
        ans += vowels[i++];
      }
    }
    while (i < vowels.size()) ans += vowels[i++];
    while (j < consonants.size()) ans += consonants[j++];
    return ans;
  }
};
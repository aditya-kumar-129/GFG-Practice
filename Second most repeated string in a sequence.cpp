#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string secFrequent(string arr[], int n) {
    map<string, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    int first = INT_MIN, second = INT_MIN;
    for (auto it : mp) {
      if (it.second > first) {
        second = first;
        first = it.second;
      }
      else if (it.second > second && it.second != first) {
        second = it.second;
      }
    }
    /*
    31
    xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa xzfxmffa rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw rylllkw

    For this particular case map contents are:-
    rylllkw --->20
    xzfxmffa --->11

    So when you don't write the else if condition then in that case second contains INT_MIN and due to which nothing will get return due to which segmentation fault get occured.
    */
    for (auto it : mp) {
      if (it.second == second)
        return it.first;
    }
  }
};
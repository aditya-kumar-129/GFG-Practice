#include <bits/stdc++.h>
using namespace std;

// Concept of next_permution should be clear in order to solve this problem

class Solution {
public:
  int findNext(int n) {
    // Storing each digit of a number in the vector
    vector<int> v;
    while (n) {
      v.push_back(n % 10);
      n /= 10;
    }
    // To get the number in the correct form we have to reverse the vector
    reverse(v.begin(), v.end());
    next_permutation(v.begin(), v.end());
    // Converting the vector to number
    int res = 0;
    for (auto it : v) res = it + res * 10;
    // Sorting and then converted back to number to check whether it is the last permutaion that has been passed
    sort(v.begin(), v.end());
    int temp = 0;
    for (auto it : v) temp = it + temp * 10;
    if (res == temp) return -1;
    return res;
  }
};
/*
In order to understand the method used to solve this problem watch the below youtube video
https://www.youtube.com/watch?v=droGaB8jh3w
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void arrange(long long arr[], int n) {
    for (long long int i = 0; i < n; i++) {
      arr[i] += (arr[arr[i]] % n) * n;
    }
    for (long long int i = 0; i < n; i++) {
      arr[i] = arr[i] / n;
    }
  }
};
// Question Link :- https://practice.geeksforgeeks.org/problems/buildings-receiving-sunlight3032/1
// Question Link :- https://practice.geeksforgeeks.org/problems/facing-the-sun2126/1

#include <bits/stdc++.h>
using namespace std;
// Concept is same as that of Traping rain water problem

class Solution {
public:
  int longest(int arr[], int n) {
    int count = 1, maximumHeight = arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] >= maximumHeight)
        maximumHeight = arr[i], count++;
    }
    return count;
  }
};
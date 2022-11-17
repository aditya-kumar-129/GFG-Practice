#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countBuildings(int h[], int n)
  {
    int count = 1;
    int max = h[0];
    for (int i = 1; i < n; i++)
      if (h[i] > max)
        max = h[i], count++;
    return count;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minEnergy(int arr[], int n)
  {
    int initMinEnergy = 0;
    int currEnergy = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
      currEnergy += arr[i];
      if (currEnergy <= 0)
      {
        initMinEnergy += abs(currEnergy) + 1;
        currEnergy = 1;
        flag = 1;
      }
    }
    return (flag == 0) ? 1 : initMinEnergy;
  }
};
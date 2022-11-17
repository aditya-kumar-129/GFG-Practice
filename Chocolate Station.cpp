#include <bits/stdc++.h>
using namespace std;

int getChocolateCost(vector<int> v, int chocolateMRP)
{
  int chocolate_bought = v[0];
  int chocolate_balance = 0;
  for (int i = 0; i < v.size() - 1; i++)
  {
    int diff = v[i] - v[i + 1];
    if (diff > 0)
      chocolate_balance += diff;
    else
    {
      if (chocolate_balance > abs(diff))
        chocolate_balance -= abs(diff);
      else
      {
        chocolate_bought += (abs(diff) - chocolate_balance);
        chocolate_balance = 0;
      }
    }
  }
  return chocolate_bought * chocolateMRP;
}
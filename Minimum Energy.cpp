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

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int i, a[n];
    for (i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.minEnergy(a, n) << endl;
  }
  return 0;
}
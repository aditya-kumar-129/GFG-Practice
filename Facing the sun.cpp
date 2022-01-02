#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countBuildings(int h[], int n)
  {
    int left_max[n], count = 1;
    int max = h[0];
    for (int i = 1; i < n; i++)
      if (h[i] > max)
        max = h[i], count++;
    return count;
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
    int h[n];
    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
    }
    Solution ob;
    auto ans = ob.countBuildings(h, n);
    cout << ans << "\n";
  }
  return 0;
}
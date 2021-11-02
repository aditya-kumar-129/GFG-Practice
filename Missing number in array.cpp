#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  //  it only contains distinct integers in the range of 1 to N.
  int MissingNumber(vector<int> &a, int n)
  {
    int total = n * (n + 1) / 2;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
      total -= a[i];
    return total;
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
    vector<int> array(n - 1);
    for (int i = 0; i < n - 1; ++i)
      cin >> array[i];
    Solution obj;
    cout << obj.MissingNumber(array, n) << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findFloor(vector<long long> v, long long n, long long x)
  {
    for (long long i = n - 1; i >= 0; i--)
      if (v[i] <= x)
        return i;
    return -1;
  }
};

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
      long long temp;
      cin >> temp;
      v.push_back(temp);
    }
    Solution obj;
    cout << obj.findFloor(v, n, x) << endl;
  }
  return 0;
}
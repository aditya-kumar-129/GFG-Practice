#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isProduct(int arr[], int n, long long x)
  {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] != 0 && x % arr[i] == 0 && s.find(x / arr[i]) != s.end())
        return 1;
      s.insert(arr[i]);
    }
    return 0;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    long long x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    auto ans = ob.isProduct(arr, n, x);
    cout << (ans ? "Yes\n" : "No\n");
  }
  return 0;
}
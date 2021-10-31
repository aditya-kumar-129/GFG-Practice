#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstRepeated(int arr[], int n)
  {
    unordered_map<int, int> unma;
    for (int i = 0; i < n; i++)
      unma[arr[i]]++;
    for (int i = 0; i < n; i++)
      if (unma[arr[i]] >= 2)
        return i + 1;
    return -1;
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
    int arr[n];
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    Solution ob;
    cout << ob.firstRepeated(arr, n) << "\n";
  }
  return 0;
}
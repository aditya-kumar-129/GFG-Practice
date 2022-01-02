// See the youtube video for explanation of 1st method:- https://youtu.be/5L9Jrehvoew
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getPairsCount(int arr[], int n, int k)
  {
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (m.find(k - arr[i]) != m.end())
        count += m[k - arr[i]]; // Since we have to consider solution which includes DUPLICATE ELEMENT ALSO
      m[arr[i]]++;
    }
    return count;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    auto ans = ob.getPairsCount(arr, n, k);
    cout << ans << "\n";
  }
  return 0;
}
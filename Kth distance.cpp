#include <bits/stdc++.h>
using namespace std;
/*
See the below link to get better understanding of the problem:-
https://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/
*/
class Solution
{
public:
  bool checkDuplicatesWithinK(int a[], int n, int k)
  {
    unordered_map<int, int> m;
    bool b = 0;
    int i;
    for (i = 0; i < n; i++)
    {
      if (m.find(a[i]) == m.end())
        m[a[i]] = i;
      else
      {
        if ((i - m[a[i]]) <= k)
        {
          b = 1;
          break;
        }
        m[a[i]] = i;
      }
    }
    return b;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    auto ans = ob.checkDuplicatesWithinK(arr, n, k);
    if (ans)
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
} // } Driver Code Ends
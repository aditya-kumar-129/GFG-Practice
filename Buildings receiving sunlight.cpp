#include <bits/stdc++.h>
using namespace std;
// Concept is same as that of Traping rain water problem
// Same Question is for :- Facing the sun.cpp

class Solution
{
public:
  int longest(int arr[], int n)
  {
    int count = 1;
    int maximum_height = arr[0];
    for (int i = 1; i < n; i++)
    {
      if (arr[i] >= maximum_height)
      {
        maximum_height = arr[i];
        count++;
      }
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
    int n;
    cin >> n;
    int i, arr[n + 5];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.longest(arr, n) << endl;
  }
  return 0;
}
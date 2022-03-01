#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstRepeated(int arr[], int n)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
      m[arr[i]]++;
    for (int i = 0; i < n; i++)
      if (m[arr[i]] > 1)
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

// Method 2:-  USing Set STL

int firstRepeated(int arr[], int n)
{
  int index = -1;
  unordered_set<int> s;
  // WARNING:- HERE WE TRAVERSE FROM BACKWARD as we have to tell the minimum index value which has ocuured 
  for (int i = n - 1; i >= 0; i--)
  {
    if (s.find(arr[i]) != s.end())
      index = i;
    else
      s.insert(arr[i]);
  }
  if (index == -1)
    return index;
  else
    return index + 1;
}
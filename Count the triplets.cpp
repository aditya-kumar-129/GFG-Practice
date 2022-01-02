// See the below youtube video for better understanding of the program
// https://www.youtube.com/watch?v=ZD7WxJ3O2XE

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countTriplet(int arr[], int n)
  {
    sort(arr, arr + n);
    int count = 0;
    for (int i = n - 1; i > 1; i--)
    {
      for (int m = 0, n = i - 1; n > m;)
      {
        if (arr[m] + arr[n] == arr[i])
          count++;
        if (arr[m] + arr[n] > arr[i])
          n--;
        else
          m++;
      }
    }
    return count;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.countTriplet(arr, n) << "\n";
  }
  return 0;
}

// Method 2 :- When you want to use the space Space Complexity :- O(n)
int countTriplet(int A[], int n)
{
  unordered_map<int, int> mp;
  int count = 0;
  for (int i = 0; i < n; i++)
    mp[A[i]] = 1;

  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (mp[A[i] + A[j]] == 1)
        count++;
  return count;
}
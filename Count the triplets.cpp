// See the below youtube video for better understanding of the program
// https://www.youtube.com/watch?v=ZD7WxJ3O2XE

#include <bits/stdc++.h>
using namespace std;

// This will work only in case when the array contains distinct elements
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
  cin.tie(nullptr);
  cout.tie(nullptr);
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

// When the array contains duplicate elements then in that case use the below method:- 

int countWays(int arr[], int n)
{
  // compute the max value in the array and create frequency array of size max_val + 1.
  int max_val = 0;
  for (int i = 0; i < n; i++)
    max_val = max(max_val, arr[i]);
  int freq[max_val + 1] = { 0 };
  for (int i = 0; i < n; i++)
    freq[arr[i]]++;

  int ans = 0;

  // Case 1: 0, 0, 0
  ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;

  // Case 2: 0, x, x
  for (int i = 1; i <= max_val; i++)
    ans += freq[0] * freq[i] * (freq[i] - 1) / 2;

  // Case 3: x, x, 2*x
  for (int i = 1; 2 * i <= max_val; i++)
    ans += freq[i] * (freq[i] - 1) / 2 * freq[2 * i];

  // Case 4: x, y, x + y
  // iterate through all pairs (x, y)
  for (int i = 1; i <= max_val; i++)
    for (int j = i + 1; i + j <= max_val; j++)
      ans += freq[i] * freq[j] * freq[i + j];

  return ans;
}

int main()
{
  int arr[] = { 1, 1, 1, 2, 2 };
  int n = sizeof(arr) / sizeof(int);
  cout << (countWays(arr, n));
  return 0;
}
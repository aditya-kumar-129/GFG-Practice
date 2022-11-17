#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsertK(vector<int>v, int N, int k)
  {
    return lower_bound(v.begin(), v.end(), k) - v.begin();
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    vector<int>Arr(N);
    for (int i = 0;i < N;i++)
      cin >> Arr[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.searchInsertK(Arr, N, k) << endl;
  }
  return 0;
} 

// Method 2 :- 

class Solution {
public:
  int searchInsertK(vector<int>v, int n, int k)
  {
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (v[mid] == k)
        return mid;
      else if (v[mid] > k)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return high + 1;
  }
};
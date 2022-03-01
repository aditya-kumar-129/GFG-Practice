#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int binary_search(int arr[], int l, int h, int x)
  {
    while (l <= h)
    {
      int mid = (l + h) / 2;
      if (arr[mid] <= x)
        l = mid + 1;
      else
        h = mid - 1;
    }
    return h;
  }

  vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
  {
    vector<int> v;
    sort(arr2, arr2 + n);
    for (int i = 0; i < m; i++)
    {
      int index = binary_search(arr2, 0, n - 1, arr1[i]);
      v.push_back(index + 1);
    }
    return v;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int m, n;
    cin >> m >> n;
    int arr1[m], arr2[n];
    for (int i = 0; i < m; i++)
      cin >> arr1[i];
    for (int j = 0; j < n; j++)
      cin >> arr2[j];
    Solution obj;
    vector<int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}

// Method 2:- Using upper_bound() function

vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
  sort(arr2, arr2 + n);
  vector<int> ans;
  for (int i = 0;i < m;i++) 
  {
    int x = upper_bound(arr2, arr2 + n, arr1[i]) - arr2;
    ans.push_back(x);
  } 
  return ans;
}

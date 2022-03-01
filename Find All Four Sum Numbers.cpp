#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    set<vector<int>> ans;     // Set is used to sort the tuples and to identify the unique tuples only
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int sum;
    for (int i = 0; i < n - 3; i++)
    {
      for (int j = i + 1; j < n - 2; j++)
      {
        int left = j + 1;
        int right = n - 1;
        while (left < right)
        {
          sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target)
            right--;
          else if (sum == target)
          {
            vector<int> t;
            t.push_back(nums[i]);
            t.push_back(nums[j]);
            t.push_back(nums[left]);
            t.push_back(nums[right]);
            ans.insert(t);
            left++;
            right--;
          }
          else
            left++;
        }
      }
    }
    vector<vector<int>> res;
    for (auto it : ans)
      res.push_back(it);
    return res;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    vector<vector<int>> ans = ob.fourSum(a, k);
    for (auto &v : ans)
    {
      for (int &u : v)
        cout << u << " ";
      cout << "$";
    }
    if (ans.empty())
      cout << -1;
    cout << "\n";
  }
  return 0;
}

// Method 2 (In this method you don't have to use set)
vector<vector<int>> fourSum(vector<int> &nums, int k)
{
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n - 3; i++)
  {
    for (int j = i + 1; j < n - 2; j++)
    {
      int l = j + 1, r = n - 1;
      while (l < r)
      {
        if (nums[i] + nums[j] + nums[l] + nums[r] == k)
        {
          vector<int> v = {nums[i], nums[j], nums[l], nums[r]};
          res.push_back(v);
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          l++;
          r--;
        }
        else if (nums[i] + nums[j] + nums[l] + nums[r]<k)
          l++;
        else
          r--;
      }
      //Using the below while loop we escape the pairs that contains the duplicate values and hence we don't need any set data structure
      while (j + 1 < nums.size() - 1 && nums[j] == nums[j + 1])
        j++;
    }
    //Using the below while loop we escape the pairs that contains the duplicate values and hence we don't need any set data structure
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
      i++;
  }
  return res;
}
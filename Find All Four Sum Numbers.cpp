#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> ans;     // Set is used to sort the tuples and to identify the unique tuples only
    int n = nums.size(), sum;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++) {
      for (int j = i + 1; j < n - 2; j++) {
        int left = j + 1, right = n - 1;
        while (left < right) {
          sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target) right--;
          else if (sum == target) {
            ans.insert({ nums[i], nums[j], nums[left++], nums[right--] });
          }
          else left++;
        }
      }
    }
    vector<vector<int>> res(ans.begin(), ans.end());
    return res;
  }
};

// Method 2 (In this method you don't have to use set)
vector<vector<int>> fourSum(vector<int>& nums, int k) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      int left = j + 1, right = n - 1;
      while (left < right) {
        if (nums[i] + nums[j] + nums[left] + nums[right] == k) {
          vector<int> v = { nums[i], nums[j], nums[left], nums[right] };
          res.push_back(v);
          while (left < right && nums[left] == nums[left + 1]) left++;
          while (left < right && nums[right] == nums[right - 1]) right--;
          left++;
          right--;
        }
        else if (nums[i] + nums[j] + nums[left] + nums[right] < k) left++;
        else right--;
      }
      //Using the below while loop we escape the pairs that contains the duplicate values and hence we don't need any set data structure
      while (j + 1 < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
    }
    //Using the below while loop we escape the pairs that contains the duplicate values and hence we don't need any set data structure
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
  }
  return res;
}
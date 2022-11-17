#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // OPTIMISED SOLUTION
  // Time Complexity = O(N)
  // Space Complexity = O(1)
  vector<int> singleNumber(vector<int> nums)
  {
    vector<int> ans;
    int num = 0;
    for (int it : nums)
      num ^= it;
    int rightmost_set_bit = num & ~(num - 1);
    int first_non_repeating_number = 0, second_non_repeating_number = 0;
    for (int it : nums)
    {
      if (rightmost_set_bit & it)
        first_non_repeating_number ^= it;
      else
        second_non_repeating_number ^= it;
    }
    ans.push_back(min(first_non_repeating_number, second_non_repeating_number));
    ans.push_back(max(first_non_repeating_number, second_non_repeating_number));
    return ans;
  }
};

// Method 2 :- 
// Time Complexity = O(nlogn)
// Space Complexity = O(1)
vector<int> singleNumber(vector<int> nums)
{
  vector<int> v;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != nums[i + 1])
      v.push_back(nums[i]);
    else
      i++;
  }
  return v;
}

// Method 2 :- 
// Time Complexity = O(n)
// Space Complexity = O(n)

vector<int> singleNumber(vector<int> nums)
{
  map<int, int> m;
  for (auto it : nums)
    m[it]++;
  vector<int> ans;
  for (auto it : m)
    if (it.second == 1)
      ans.push_back(it.first);
  return ans;
}

// OPTIMISED SOLUTION
// Time Complexity = O(N)
// Space Complexity = O(1)
vector<int> singleNumber(vector<int> nums)
{
  int sum = 0;
  for (int i = 0;i < nums.size();i++)
    sum = sum ^ nums[i];
  /*
  Another way of finding the rightmost set bit is to calculate the trailing zeores present in the given number
  for (int i = 0;i < 32;i++)
  {
    if ((sum & (1 << i)) > 0)
    {
      pos = i;
      break;
    }
  }
  */
  // One more way of finding the right most set bit
  int pos;
  pos = __builtin_ctz(sum);
  int num1 = 0, num2 = 0;
  for (int i = 0;i < nums.size();i++)
  {
    if ((nums[i] & (1 << pos)) > 0)
      num1 = num1 ^ nums[i];
    else
      num2 = num2 ^ nums[i];
  }
  vector<int> s;
  if (num1 > num2)
    s.push_back(num2), s.push_back(num1);
  else
    s.push_back(num1), s.push_back(num2);
  return s;
}
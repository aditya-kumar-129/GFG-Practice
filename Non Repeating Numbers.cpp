#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> v(2 * n + 2);
    for (int i = 0; i < 2 * n + 2; i++)
      cin >> v[i];
    Solution ob;
    vector<int> ans = ob.singleNumber(v);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}

// Method 2 :- Below method uses Space Complexity of O(n)
// BRUTE FORCE APPROACH

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
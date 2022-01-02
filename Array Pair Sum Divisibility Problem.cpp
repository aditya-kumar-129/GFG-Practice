#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canPair(vector<int> v, int k)
  {
    int n = v.size();
    if (n % 2 == 1)
      return false;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
      freq[v[i] % k]++;

    for (int i = 0; i < n; i++)
    {
      int rem = v[i] % k;
      if (2 * rem == k)
      {
        if (freq[rem] % 2 == 1)
          return false;
      }
      else if (rem == 0)
      {
        if (freq[rem] % 2 == 1)
          return false;
      }
      else if (freq[rem] != freq[k - rem])
        return false;
    }
    return true;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
      cin >> nums[i];
    Solution ob;
    bool ans = ob.canPair(nums, k);
    if (ans)
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
}

// Method 2:-
bool canPair(vector<int> v, int k)
{
  int n = v.size();

  if (n % 2 == 1)
    return false;

  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
    freq[v[i] % k]++;

  if (freq[0] % 2 != 0)
    return false;

  for (int i = 1; i < k; i++)
    if (freq[i] != freq[k - i])
      return false;

  return true;
}

// Method 3:-
bool canPair(vector<int> nums, int k)
{
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
    m[((nums[i] % k) + k) % k]++;

  for (auto it : m)
  {
    int key = it.first;
    if (key == 0)
      if (it.second % 2 != 0)
        return false;
    else if (m[key] != m[k - key])
      return false;
  }
  return true;
}
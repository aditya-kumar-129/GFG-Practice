#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // BRUTE FORCE APPROACH
  //  Below method has a Time Complexiity:- O(n) and Space Complexity:- O(n)
  int solve(vector<int> v, int k, int index)
  {
    if (v.size() == 1)
      return v[0];
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    return solve(v, k, index);
  }
  int josephus(int n, int k)
  {
    k = k - 1;
    vector<int> v;
    for (int i = 1; i <= n; i++)
      v.push_back(i);
    int index = 0;
    int ans = -1;
    return solve(v, k, index);
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    Solution ob;
    cout << ob.josephus(n, k) << endl;
  }
  return 0;
}

// Method 2 :- Using recursion
// Have a look on the below yooutube video for knowing how we gwt at the return statement
// https://www.youtube.com/watch?v=dzYq5VEMZIg
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
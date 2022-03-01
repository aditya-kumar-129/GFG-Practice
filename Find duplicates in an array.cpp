#include <bits/stdc++.h>
using namespace std;
/*
Refer the below article for more explanation :-
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
*/
class Solution
{
public:
  // OPTIMISED SOLUTION
  // Time Complexity = O(N)
  // Space Complexity = O(1)
  vector<int> duplicates(int arr[], int n)
  {
    vector <int> ans;
    // Example :- Arr[] = {2, 2}
    for (int i = 0; i < n; i++)
      arr[arr[i] % n] += n;
    for (int i = 0; i < n; i++)
      if (arr[i] >= n * 2)
        ans.push_back(i);
    if (ans.size() == 0)
      ans.push_back(-1);
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t-- > 0)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution obj;
    vector<int> ans = obj.duplicates(a, n);
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
  return 0;
}

/*Method 2 :- 
OPTIMISED SOLUTION
Time Complexity = O(N)
Space Complexity = O(1)
Refer the below youtube video for better understanding :-
https://youtu.be/iiYc32-4ZJY
*/

vector<int> duplicates(int arr[], int n)
{
  vector<int> res;
  for (int i = 0; i < n; i++)
    arr[arr[i] % n] += n;
  for (int i = 0; i < n; i++)
    arr[i] /= n;
  for (int i = 0; i < n; i++)
    if (arr[i] > 1)
      res.push_back(i);
  if (res.size() == 0)
    res.push_back(-1);
  return res;
}

// Method 2:- 
// Time Complexity = O(nlogn)
// Space Complexity = O(n)
vector<int> duplicates(int arr[], int n)
{
  vector<int> v;
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++)
    freq[arr[i]]++;
  for (auto& value : freq)
    if (value.second > 1)
      v.push_back(value.first);
  if (v.size() == 0)
    v.push_back(-1);
  sort(v.begin(), v.end());
  return v;
}
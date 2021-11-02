#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> duplicates(int arr[], int n)
  {
    vector<int> v;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
      freq[arr[i]]++;
    for (auto &value : freq)
      if (value.second > 1)
        v.push_back(value.first);
    if (v.size() == 0)
      v.push_back(-1);
    sort(v.begin(), v.end());
    return v;
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
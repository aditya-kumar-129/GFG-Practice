#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> duplicates(int arr[], int n)
  {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[arr[i]]++; //for frequency

    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
      if (v[i] > 1)
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
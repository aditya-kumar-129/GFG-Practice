#include <bits/stdc++.h>
using namespace std;

// WHEN USED INBUILT sort() FUNCTION THEN IT GIVES TLE AS INBUILT sort() HAS A TIME COMPLEXITY OF nlog(n);
class Solution
{
public:
  vector<int> SortBinaryArray(vector<int> v)
  {
    int count_zero = 0, count_one = 0;
    for (auto e : v)
    {
      if (e == 1)
        count_one++;
      else
        count_zero++;
    }
    vector<int> ans;
    for (int i = 0; i < count_zero; i++)
      ans.push_back(0);
    for (int i = 0; i < count_one; i++)
      ans.push_back(1);
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> binArray(n);
    for (int i = 0; i < n; i++)
      cin >> binArray[i];
    Solution ob;
    vector<int> result = ob.SortBinaryArray(binArray);
    for (int i = 0; i < n; i++)
      cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
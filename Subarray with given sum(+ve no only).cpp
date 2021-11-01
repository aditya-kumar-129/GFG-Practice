#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> subarraySum(int arr[], int n, long long s)
  {
    int last = 0;
    int start = 0;
    unsigned long long currsum = 0;
    bool flag = false;
    vector<int> res;
    
    for (int i = 0; i < n; i++)
    {
      currsum += arr[i];
      if (currsum >= s)
      {
        last = i;
        while (s < currsum && start < last)
        {
          currsum -= arr[start];
          ++start;
        }
        //now if current sum becomes equal to given number, we store the starting and ending index for the subarray.
        if (currsum == s)
        {
          res.push_back(start + 1);
          res.push_back(last + 1);
          flag = true;
          break;
        }
      }
    }
    if (flag == false)
      res.push_back(-1);
    return res;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    long long s;
    cin >> n >> s;
    int arr[n];
    const int mx = 1e9;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> res;
    res = ob.subarraySum(arr, n, s);
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
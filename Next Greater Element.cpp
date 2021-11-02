#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> nextLargerElement(vector<long long> arr, int n)
  {
    // Your code here
    stack<long long> s;
    vector<long long> vec;
    //vec.push_back(-1);
    for (int i = n - 1; i >= 0; i--)
    {
      if (s.empty())
        vec.push_back(-1);
      else if (s.top() < arr[i])
      {
        while (!s.empty() && s.top() < arr[i])
          s.pop();
        if (s.empty())
          vec.push_back(-1);
        else if (s.top() > arr[i])
          vec.push_back(s.top());
      }
      else if (s.top() > arr[i])
        vec.push_back(s.top());
      s.push(arr[i]);
    }
    reverse(vec.begin(), vec.end());
    return vec;
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
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution obj;
    vector<long long> res = obj.nextLargerElement(arr, n);
    for (long long i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Recursive Approach 
  vector<string> generateCode(int n)
  {
    if (n <= 0)
      return {"0"};

    if (n == 1)
      return {"0", "1"};

    vector<string> prev_res = generateCode(n - 1);
    vector<string> res;
    for (int i = 0; i < prev_res.size(); i++)
    {
      string s = prev_res[i];
      res.push_back("0" + s);
    }

    for (int i = prev_res.size() - 1; i >= 0; i--)
    {
      string s = prev_res[i];
      res.push_back("1" + s);
    }
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
    cin >> n;
    Solution obj;
    vector<string> res = obj.generateCode(n);
    for (string i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}

// Method 2 :-  Iterative Approach

vector<string> generateCode(int N)
{
  vector<string> res = {"0", "1"};
  if (N == 1)
    return res;
  for (int i = 1; i < N; i++)
  {
    vector<string> temp;
    for (int i = 0; i < res.size(); i++)
    {
      if (i % 2 == 0)
      {
        temp.push_back(res[i] + "0");
        temp.push_back(res[i] + "1");
      }
      else
      {
        temp.push_back(res[i] + "1");
        temp.push_back(res[i] + "0");
      }
    }
    res = temp;
  }
  return res;
}
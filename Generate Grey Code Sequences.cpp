#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Recursive Approach 
  vector <string> generateCode(int n)
  {
    vector<string> v;
    if (n == 1)
    {
      v.push_back("0");
      v.push_back("1");
      return v;
    }
    vector<string> res = generateCode(n - 1);
    for (int i = 0;i < res.size();i++)
    {
      string str = "0";
      str += res[i];
      v.push_back(str);
    }
    for (int i = res.size() - 1;i >= 0;i--)
    {
      string str = "1";
      str += res[i];
      v.push_back(str);
    }
    return v;
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

vector <string> generateCode(int N)
{
  vector<string> ans{ "0", "1" };
  for (int i = 2; i <= N; i++) 
  {
    int len = ans.size();
    for (int i = 0; i < len; i++) 
      ans[i] = "0" + ans[i];
    for (int i = len-1; i >=0; i--) 
      ans.push_back("1" + ans[i]);
  }
  return ans;
}

// Method 3 :- Using bitset Don't know the logic

vector <string> generateCode(int N)
{
  vector<string> ans;
  for (int i = 0; i < (1 << N); i++)
  {
    bitset<16> curr((i ^ (i >> 1)));
    string s = curr.to_string();
    ans.emplace_back(s.substr(16 - N));
  }
  return ans;
}

vector <string> generateCode(int N)
{
  vector <string> res;
  int num = pow(2, N);
  for (int i = 0; i < num; i++) {
    string str = "";
    int gray = i ^ (i >> 1);
    str = bitset<16>(gray).to_string();
    str = str.substr(16 - N, N);
    res.push_back(str);
  }
  return res;
}
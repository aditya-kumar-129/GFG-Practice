#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string findSum(string x, string y)
  {
    string ans;
    if (x.length() > y.length())
      swap(x, y);
    int i, carry = 0, n = x.length(), m = y.length();
    for (i = n - 1; i >= 0; --i)
    {
      int sum = (x[i] - '0') + (y[i + m - n] - '0') + carry;
      ans += sum % 10 + '0';
      carry = sum / 10;
    }
    for (i = m - n - 1; i >= 0; --i)
    {
      int sum = (y[i] - '0') + carry;
      ans += sum % 10 + '0';
      carry = sum / 10;
    }
    if (carry > 0)
      ans += carry + '0';
    int a = ans.length();
    for (i = a - 1; i > 0; --i)
    {
      if (ans[i] != '0')
        break;
      if (ans[i] == '0')
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    string x, y;
    cin >> x >> y;
    Solution ob;
    cout << ob.findSum(x, y) << "\n";
  }
  return 0;
}

// 2nd method

string findSum(string x, string y)
{
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  int xlen = x.length();
  int ylen = y.length();
  int min_len = min(xlen, ylen);
  int i = 0, sum = 0, carry = 0;
  string result = "";
  while (i < min_len)
  {
    int sum = (x[i] - '0') + (y[i] - '0') + carry;
    result += to_string(sum % 10);
    carry = sum / 10;
    i++;
  }
  while (i < xlen)
  {
    int sum = (x[i] - '0') + carry;
    result += to_string(sum % 10);
    carry = sum / 10;
    i++;
  }
  while (i < ylen)
  {
    int sum = (y[i] - '0') + carry;
    result += to_string(sum % 10);
    carry = sum / 10;
    i++;
  }
  if (carry > 0)
    result += to_string(carry);
  reverse(result.begin(), result.end());
  int num = stoi(result);
  result = to_string(num);
  return result;
}
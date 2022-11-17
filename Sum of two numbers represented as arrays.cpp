#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findSum(vector<int> &a, vector<int> &b)
  {
    vector<int> res;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0, sum = 0, digit;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
      sum = a[i++] + b[j++] + carry;
      digit = sum % 10;
      carry = sum / 10;
      res.push_back(digit);
    }
    while (i < a.size())
    {
      sum = a[i++] + carry;
      carry = sum / 10;
      digit = sum % 10;
      res.push_back(digit);
    }
    while (j < b.size())
    {
      sum = b[j++] + carry;
      carry = sum / 10;
      digit = sum % 10;
      res.push_back(digit);
    }
    if (carry != 0)
      res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
  }
};

// Method2:- Without reversing the vector and moving the pointer from last index to 0
vector<int> findSum(vector<int> &a, vector<int> &b)
{
  vector<int> res;
  int carry = 0;
  int i = a.size() - 1;
  int j = b.size() - 1;
  while (i >= 0 || j >= 0 || carry)
  {
    int val = 0;
    if (i >= 0)
      val = val + a[i--];
    if (j >= 0)
      val = val + b[j--];
    val = val + carry;
    res.push_back(val % 10);
    carry = val / 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
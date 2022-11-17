#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Method 1 :-  In this case we have padded the input before the calculation so that the length of both the string are now equal and their should be no overhead to do calculation after calculating till equal length .

  string addBinary(string A, string B)
  {
    if (A.length() > B.length())
      return addBinary(B, A);

    int diff = B.length() - A.length();

    string padding;
    for (int i = 0; i < diff; i++)
      padding.push_back('0');

    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
      if (A[i] == '1' && B[i] == '1')
      {
        if (carry == '1')
          res.push_back('1'), carry = '1';
        else
          res.push_back('0'), carry = '1';
      }
      else if (A[i] == '0' && B[i] == '0')
      {
        if (carry == '1')
          res.push_back('1'), carry = '0';
        else
          res.push_back('0'), carry = '0';
      }
      else if (A[i] != B[i])
      {
        if (carry == '1')
          res.push_back('0'), carry = '1';
        else
          res.push_back('1'), carry = '0';
      }
    }

    if (carry == '1')
      res.push_back(carry);
    reverse(res.begin(), res.end());

    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
      index++;
    return (res.substr(index));
  }
};

// Method 2:-

string addBinary(string A, string B)
{
  // your code here
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  string ans;
  char carry = '0';
  int i = 0;
  while (i < A.length() && i < B.length())
  {
    if (A[i] == '0' && B[i] == '0') // 001 000
      ans += carry, carry = '0';
    else if (A[i] == '1' && B[i] == '1') // 110  111
      ans += carry, carry = '1';
    else // 101 100 011 010
    {
      if (carry == '0')
        ans += '1';
      else
        ans += '0';
    }
    i++;
  }

  while (i < A.length())
  {
    if (A[i] == carry) // 11 00
      ans += '0';
    else // 01 10
    {
      ans += '1';
      if (carry == '1')
        carry = '0';
    }
    i++;
  }
  while (i < B.length())
  {
    if (B[i] == carry) // 11 00
      ans += '0';
    else // 01 10
    {
      ans += '1';
      if (carry == '1')
        carry = '0';
    }
    i++;
  }

  if (carry == '1')
    ans += carry;

  // This part is very important
  // To remove leading zeroes
  while (ans[ans.length() - 1] == '0')
    ans = ans.substr(0, ans.size() - 1);

  reverse(ans.begin(), ans.end());
  return ans;
}

// Method :- 3
string addBinary(string A, string B)
{
  int i = A.size() - 1;
  int j = B.size() - 1;
  string res;

  int carry = 0;
  while (i >= 0 || j >= 0)
  {
    int digit1 = 0;
    int digit2 = 0;
    if (i >= 0)
      digit1 = A[i] - '0';
    if (j >= 0)
      digit2 = B[j] - '0';
    int sum = digit1 + digit2 + carry;
    int resdigit = 0;
    if (sum == 0)
      resdigit = 0, carry = 0;
    else if (sum == 1)
      resdigit = 1, carry = 0;
    else if (sum == 2)
      resdigit = 0, carry = 1;
    else if (sum == 3)
      resdigit = 1, carry = 1;
    res.push_back(resdigit + '0');
    if (i >= 0)
      i--;
    if (j >= 0)
      j--;
  }
  if (carry != 0)
    res.push_back(carry + '0');
  reverse(res.begin(), res.end());
  // To remove leading zeroes
  int start = 0;
  while (start < res.size() && res[start] == '0')
    start++;
  return res.substr(start);
}
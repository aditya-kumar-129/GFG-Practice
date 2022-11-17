#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  vector<string> tens = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  vector<string> places = {"thousand", "lakh", "crore"};

  string twoDigits(int x, int y)
  {
    if (x == 0)
      return ones[y];
    else if (x == 1)
    {
      int num = 10 * x + y;
      return ones[num];
    }
    string first = tens[x - 2];
    string second = ones[y];
    if (!second.empty())
      return first + " " + second;
    return first;
  }

  string convertToWords(long n)
  {
    if (n == 0)
      return "zero";
    else if (n < 20)
      return ones[n];
    string number = to_string(n);
    int size = number.size();
    int i = size - 1;
    string ans = "";
    int place = -1;
    stack<string> st;
    while (i >= 0)
    {
      int d1 = 0, d2 = 0;
      d1 = number[i] - '0';
      if (i - 1 >= 0)
        d2 = number[i - 1] - '0';
      string temp = twoDigits(d2, d1);
      if (size == 2)
        return temp; //only 2 digits
      else if (i == size - 1 && !temp.empty())
        temp = "and " + temp;
      if (i == size - 1 && size >= 3)
      {
        string third = "";
        if (i - 2 >= 0)
        {
          int d3 = number[i - 2] - '0';
          third = ones[d3];
          if (!third.empty())
            third = third + " hundred ";
        }
        temp = third + temp;
        i -= 1;
      }
      if (place >= 0)
      {
        if (!temp.empty())
          temp = temp + " " + places[place] + " ";
      }
      st.push(temp);
      i -= 2;
      place++;
    }
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};
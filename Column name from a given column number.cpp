#include <bits/stdc++.h>
using namespace std;

/*
Below is the youtube video for the explanation of the below method:-
https://youtu.be/UcTKk2y_3s4
When you take A as 0 B as 1 and so on Z as 25
*/

class Solution
{
public:
  string colName(long long int n)
  {
    string result = "";
    while (n)
    {
      char c = 'A' + (n - 1) % 26;
      result = c + result;
      n = (n - 1) / 26;
    }
    return result;
  }
};
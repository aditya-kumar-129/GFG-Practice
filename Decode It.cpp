#include<bits/stdc++.h>
using namespace std;

// I don't know why isdigit() function does not work here :( because may be that the input given is character may be this is the reason

class Solution
{
public:
  char decodeIt(string str, int k)
  {
    string s, temp = "";
    for (int i = 0; i < str.length(); i++)
    {
      if (int(str[i]) >= 49 && int(str[i]) <= 57)  // checking if the character is any number 
      {
        temp = s;
        int val = int(str[i]) - 49;
        for (int j = 0; j < val; j++)
          s = s + temp;
      }
      else
        s = s + str[i];
    }
    return s[k - 1];
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    int k;
    cin >> k;
    Solution ob;
    cout << ob.decodeIt(str, k) << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isValid(string s)
  {
    int c1 = 0;
    int c2 = 0;
    int n = s.length();
    string str = "";
    for (int i = 0; i < n; i++) // count the no of . present in the string 
      if (s[i] == '.')
        c1++;
    if (c1 != 3)  //if it is less than three then return 0
      return 0;
    for (int i = 0; i < n; i++)
    {
      /* isalpha(c) is a function in C which can be used to check if the passed character is an alphabet or not.It returns a non-zero value if it’s an alphabet else it returns 0*/

      if (isalpha(s[i]))   // if any alphabetical character is present then return 0
        return 0;
      if (s[i] != '.')
        str += s[i];
      else
      {
        // if the no of digit is eqaul to zero which means that two dots occur simultaneously and if the no of digit is greater than 3 which means that the total no of digit present between the two digit is greater than 255 then return 0.
        if (str.length() == 0 || str.length() > 3)  
          return 0;
        /*
        Below is the article for more refernce:-
        https://www.geeksforgeeks.org/converting-strings-numbers-cc/
        preview:-
        String conversion using stoi():- The stoi() function takes a string as an argument and returns its value.
        */
        int num = stoi(str);
        if (num < 0 || num > 255)
          return 0;
        str = "";
      }
      /*
      To valid such kind of inputs the below code is written
      00.00.00.00
      */
      if (str[0] == '0' && str.length() > 1)
        return 0;
    }
    return 1;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.isValid(s) << endl;
  }
  return 0;
}
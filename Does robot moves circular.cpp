#include <bits/stdc++.h>
using namespace std;

string isCircular(string s)
{
  int n = s.length();
  int i = 0;
  int x = 0, y = 0;
  char c = 'R';
  while (i < n)
  {
    if (s[i] == 'L')
    {
      if (c == 'R')
        c = 'U';
      else if (c == 'U')
        c = 'L';
      else if (c == 'L')
        c = 'D';
      else
        c = 'R';
    }
    else if (s[i] == 'R')
    {
      if (c == 'R')
        c = 'D';
      else if (c == 'U')
        c = 'R';
      else if (c == 'L')
        c = 'U';
      else
        c = 'L';
    }
    else
    {
      if (c == 'R')
        x++;
      else if (c == 'U')
        y++;
      else if (c == 'L')
        x--;
      else
        y--;
    }
    i++;
  }
  if (x == 0 && y == 0)
    return "Circular";
  else
    return "Not Circular";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string path;
    cin >> path;
    cout << isCircular(path) << endl;
  }
  return 0;
}

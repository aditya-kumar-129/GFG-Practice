#include <bits/stdc++.h>
using namespace std;

string isCircular(string s) {
  int n = s.length(), i = 0, x = 0, y = 0;
  // The idea is to consider the starting position as (0, 0) and direction as East (We can pick any values for these)
  char current_direction = 'R';
  while (i < n) {
    if (s[i] == 'L') {
      if (current_direction == 'R') current_direction = 'U';
      else if (current_direction == 'U') current_direction = 'L';
      else if (current_direction == 'L') current_direction = 'D';
      else current_direction = 'R';
    }
    else if (s[i] == 'R') {
      if (current_direction == 'R') current_direction = 'D';
      else if (current_direction == 'U') current_direction = 'R';
      else if (current_direction == 'L') current_direction = 'U';
      else current_direction = 'L';
    }
    else {
      if (current_direction == 'R') x++;
      else if (current_direction == 'U') y++;
      else if (current_direction == 'L') x--;
      else y--;
    }
    i++;
  }
  if (x == 0 && y == 0) return "Circular";
  else return "Not Circular";
}

// Method 2:- 
#define N 0
#define E 1
#define S 2
#define W 3
string isCircular(string path) {
  int x = 0, y = 0, dir = N;
  for (int i = 0;i < path.size();i++) {
    if (path[i] == 'R') dir = (dir + 1) % 4;
    else if (path[i] == 'L') dir = (dir - 1 + 4) % 4;
    else {
      if (dir == N) y++;
      else if (dir == E) x++;
      else if (dir == S) y--;
      else x--;
    }
  }
  return (x == 0 and y == 0) ? "Circular" : "Not Circular";
}
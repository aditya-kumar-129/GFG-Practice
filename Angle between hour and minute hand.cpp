#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getAngle(int h, int m)
  {
    if (h == 12)
      h = 0;
    if (m == 60)
    {
      m = 0;
      h += 1;
      if (h > 12)
        h = h - 12;
    }

    // 60 --> 1 hour
    // m min --> (1/60)*m hour
    // for 1 hour ---> 30 degree
    // (1/60)*m hour ---> (1/60)*m*30===> m/2;

    float hour_angle = 0.5 * (h * 60 + m);
    float minute_angle = 6 * m;
    float angle = abs(hour_angle - minute_angle);
    return min(360 - angle, angle);
  }
};